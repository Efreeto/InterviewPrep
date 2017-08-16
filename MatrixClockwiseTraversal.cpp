#include <iostream>
#include <string>

enum Direction
{
    North,
    East,
    South,
    West
};

// Turn input Direction clockwise
Direction TurnCW(Direction dir)
{
    if (dir == Direction::West) // special case
    {
        return Direction::North;
    }

    int new_dir = int(dir) + 1;
    return Direction(new_dir);
}

// Attach a number as characters at the end of the input string
void AttachNumberAsString(std::string& string, int number)
{
    string += std::to_string(number) + ", ";
}

void BuildStringFromMatrix(int* Matrix, int NumRows, int NumColumns, char* OutBuffer)
{
    // OutStr will be OutBuffer in std::string
    std::string OutStr;

    // Direction dir specifies how the matrix is traversed
    // dir cycles through East -> South -> West -> North -> East
    Direction dir = Direction::East;

    // range_x and range_y define how many iteration should happen for going in one direction.
    // range_x is used by East and West; range_y is used by North and South.
    // When traversing through one direction finishes, the subsequent range is reduced by one because there is one less row/col to traverse
    int range_x = NumColumns;
    int range_y = NumRows;

    // (col, row) denotes the position of the starting element in the matrix
    int row = 0;
    int col = 0;

    while (1)
    {
        // (x, y) denotes the current position of the traversal in the matrix
        int x = col;
        int y = row;

        if (dir == Direction::East)
        {
            if (range_x == 0)
            {
                break;  // No more places to go, so we're done
            }

            for (int i = 0; i < range_x; i++)
            {
                x = col + i;
                int* ptr = Matrix + x + y*NumColumns; // make ptr point to (x,y) in Matrix
                AttachNumberAsString(OutStr, *ptr);
            }

            // set the next direction
            dir = TurnCW(dir);

            // set the starting position for the next direction
            col = x;
            row = y + 1;

            // one less row/col for next direction
            range_y--;
        }
        else if (dir == Direction::South)
        {
            if (range_y == 0)
            {
                break;  // No more places to go, so we're done
            }
            for (int i = 0; i < range_y; i++)
            {
                y = row + i;
                int* ptr = Matrix + x + y*NumColumns; // make ptr point to (x,y) in Matrix
                AttachNumberAsString(OutStr, *ptr);
            }

            // set the next direction
            dir = TurnCW(dir);

            // set the starting position for the next direction
            row = y;
            col = x - 1;

            // one less row/col for next direction
            range_x--;
        }
        else if (dir == Direction::West)
        {
            if (range_x == 0)
            {
                break;  // No more places to go, so we're done
            }
            for (int i = 0; i < range_x; i++)
            {
                x = col - i;
                int* ptr = Matrix + x + y*NumColumns; // make ptr point to (x,y) in Matrix
                AttachNumberAsString(OutStr, *ptr);
            }

            // set the next direction
            dir = TurnCW(dir);

            // set the starting position for the next direction
            col = x;
            row = y - 1;

            // one less row/col for next direction
            range_y--;
        }
        else if (dir == Direction::North)
        {
            if (range_y == 0)
            {
                break;  // No more places to go, so we're done
            }
            for (int i = 0; i < range_y; i++)
            {
                y = row - i;
                int* ptr = Matrix + x + y*NumColumns; // make ptr point to (x,y) in Matrix
                AttachNumberAsString(OutStr, *ptr);
            }

            // set the next direction
            dir = TurnCW(dir);

            // set the starting position for the next direction
            row = y;
            col = x + 1;

            // one less row/col for next direction
            range_x--;
        }
    }

    if (OutStr.size() > 2)
    {
        OutStr.erase(OutStr.size() - 2);    // erase the last ", "
    }
    strcpy(OutBuffer, OutStr.c_str()); // OutBuffer = OutStr
}

void main()
{
    int Matrix[] = { 2, 3, 4, 8, 5, 7, 9, 12, 1, 0, 6, 10 };
    char OutBuffer[100];    // The size of buffer must be guaranteed to be valid and large enough to hold all of the data.
                            // It is not just the size of Matrix because it should also hold places for commas and large numbers.

    BuildStringFromMatrix(Matrix, 3, 4, OutBuffer);

    std::cout << OutBuffer << std::endl;
    // Outputs "2, 3, 4, 8, 12, 10, 6, 0, 1, 5, 7, 9"
}