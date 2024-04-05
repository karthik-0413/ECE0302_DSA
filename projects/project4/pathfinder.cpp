#include <cstdlib>
#include <iostream>
#include "lib/image.h"
#include "list.hpp"
#include "queue.hpp"
#include <vector>

struct State
{
  int Row;
  int Col;
};

class Problem
{
  public:
   // returns the initial state of the problem
   State initial(std::string input_file, Image<Pixel> &image)
    {
      // Declaring needed variables
      int Rows = 0, Cols = 0, i = 1;

      // Nested For-Loop to go through entire image
      for (int r = 0; r < image.height(); r++)
      {
        for (int c = 0; c < image.width(); c++)
        {
          // RED = initial position of the block
          if (image(r, c) == RED)
          {
            // Making sure to get ONLY one initial state
            if (i == 1)
            {
              Rows = r;
              Cols = c;
              // Returning the coordinates of the initial state
              return {Rows, Cols};
            }
            i++;
          }
        }
      }
    }

    // returns true if state is the goal state, else false
    bool goal(State state, std::string input_file, Image<Pixel> &image)
    {
      // Checking only the edges of the maze, since the goal of the maze is to get to the shortest path to the edge
      if ((state.Row == 0 || state.Row == image.height()-1 || state.Col == 0 || state.Col == image.width()-1))
      {
        return true;
      }
      return false;
    }

    // returns a list of states resulting from possible transitions from state (i.e., a list of potential next states)
    std::vector<State> actions(State state, Image<Pixel> &image)
    {
      // Declaring States that represent the order in which are instructed to check the neighboring pixels
      State next1 = {state.Row-1, state.Col};
      State next2 = {state.Row+1, state.Col};
      State next3 = {state.Row, state.Col-1};
      State next4 = {state.Row, state.Col+1};
      std::vector<State> next5;

      // If-Statement that checks if the row down the current pixel is black
      if (image(next1.Row, next1.Col) != BLACK)
      {
        // If not, then it pushs the pixel to the vector of states
        next5.push_back(next1);

        // and makes the pixel black so that we won't check the pixel again ( avoids duplicates )
        image(next1.Row, next1.Col) = BLACK;
      }

      // If-Statement that checks if the row up the current pixel is black
      if (image(next2.Row, next2.Col) != BLACK)
      {
        // If not, then it pushs the pixel to the vector of states
        next5.push_back(next2);

        // and makes the pixel black so that we won't check the pixel again ( avoids duplicates )
        image(next2.Row, next2.Col) = BLACK;
      }

      // If-Statement that checks if the column down the current pixel is black
      if (image(next3.Row, next3.Col) != BLACK)
      {
        // If not, then it pushs the pixel to the vector of states
        next5.push_back(next3);

        // and makes the pixel black so that we won't check the pixel again ( avoids duplicates )
        image(next3.Row, next3.Col) = BLACK;
      }

      // If-Statement that checks if the column up the current pixel is black
      if (image(next4.Row, next4.Col) != BLACK)
      {
        // If not, then it pushs the pixel to the vector of states
        next5.push_back(next4);

        // and makes the pixel black so that we won't check the pixel again ( avoids duplicates )
        image(next4.Row, next4.Col) = BLACK;
      }

      // Returning the vector of States that are valid
      return next5;
    }
};

// To traverse the state space, we will use the breadth-first search (BFS) algorithm
State breadth_first_search(Problem problem, std::string input_file, Image<Pixel> &image)
{
  State s = problem.initial(input_file, image);  // initial state

  // Creating a duplicate image, so that I am able to edit the original one 
  // and only change the duplicate one with the GREEN pixel that represents the solution
  Image<Pixel> image2 = image;

  // frontier = a FIFO queue with s as the initial element (unexplored states)
  Queue<State, List<State>> frontier;
  frontier.enqueue(s);

  // While the queue is not empty
  while (!frontier.isEmpty())
  {
    // s = pop next state from frontier // get a next state
    s = frontier.peekFront();
    frontier.dequeue();

    if (problem.goal(s, input_file, image))  // reached goal state
    {
      return s;
    }

    // for each state s_next in problem.actions(s) do - for each next state
    for (State s_next : problem.actions(s, image))
    {
      // insert s_next into the frontier 
      frontier.enqueue(s_next);
    }
  }

  // If the queue is empty, then return false values
  return {-1, -1};
}

int main(int argc, char *argv[])
{
  // get input/output file names from command line arguments
  if (argc != 3) {
    std::cout << "Usage: pathfinder "
              << "<first_input_filename> <second_output_filename>\n"
              << std::endl;
    return EXIT_FAILURE;
  }

  std::string input_file = argv[1];
  std::string output_file = argv[2];

  // Creating an instance of the Problem class
  Problem problem;

  try
  {
    // Read input image from file
    Image<Pixel> image;

    // Catching if the program cannot read or write the specified image files 
    try
    {
      image = readFromFile(input_file);
    }
    catch(const std::exception& e)
    {
      EXIT_FAILURE;
    }
    
    // Creating a duplicate image, so that I am able to edit the original one 
    // and only change the duplicate one with the GREEN pixel that represents the solution
    Image<Pixel> image2 = image;

    // Making sure that	the input maze image does not contain colors other than black, white, or red
    for (int i = 0; i < image.height(); i++)
    {
      for (int j = 0; j < image.width(); j++)
      {
        if (image(i, j) != BLACK && image(i, j) != RED && image(i, j) != WHITE)
        {
          return EXIT_FAILURE;
        }
      }
    }

    // Calling the breadth-first search (BFS) algorithm to find the nearest exit to the maze
    State state = breadth_first_search(problem, input_file, image);

    // ********************************************
    // Green = Nearest exit if a solution exists  *
    // Black = Walls ( Cannot be traversed )      *
    // White = Open Spaces ( Can be traversed )   *
    // Red = Initial Location                     *
    // ********************************************

    // GOAL STATE
    if (state.Row != -1 && state.Col != -1)
    {
      // If a solution exists, the output image be colored green with the quickest exit
      // and the string "Solution Found" written to standard output
      std::cout << "Solution Found" << std::endl;

      // Green = Nearest exit if a solution exists as provided by the breadth-first search (BFS) algorithm
      image2(state.Row, state.Col) = GREEN;
    }
    else
    {
      // If no solution is to be found, then the string "No Solution Found" should be written to standard output
      std::cout << "No Solution Found" << std::endl;
    }

    // Catching if the program cannot read or write the specified image files 
    try
    {
      // Write solution image to file
      writeToFile(image2, output_file);
    }
    catch(const std::exception& e)
    {
      EXIT_FAILURE;
    }
  }
  catch(const std::exception& e)
  {
    EXIT_FAILURE;
  }
    
}