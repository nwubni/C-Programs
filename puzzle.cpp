/*
 * Author: Nakuru Wubni
 * Program Name: Puzzle
 * Description: This is just a classic puzzle game where pieces are moved to sort numbers.
 * Play the game at dimension of 3 for best console expirience.
 * The 0 piece represents an empty space and other pieces move relative to its position.
 * For example, pressing the down key (k) will swap the positions
 * of any number value above zero with 0, and pressing right (j) will swap the positions
 * of any number value to the right of zero with 0.
 * Feel free to use or extend the code in any  of your projects
 * Cheers!!!
 */

#include <bits/stdc++.h>

using namespace std;

class Puzzle
{
private:
    int size{};
    int dimension{};
    vector<int> a{};
    int index{};

public:
    Puzzle(int d)
    {
        dimension = d;
        size = dimension * dimension;
        a.resize(size);
        index = 0;
    }

    void initialize()
    {
        for (int i{0}; i < size - 1; i++)
            a[i] = i + 1;

        a[size - 1] = 0;
    }

    void shuffle()
    {
        unsigned seed = std::chrono::system_clock::now()
                            .time_since_epoch()
                            .count();

        std::shuffle(a.begin(), a.begin() + (size - 2), std::default_random_engine(seed));
        index = (rand() % size);
        swap(a[size - 1], a[index]);
    }

    bool solved()
    {
        for (int i{0}; i < size - 1; i++)
        {
            if (a[i] != i + 1)
                return false;
        }

        return true;
    }

    void move(char m)
    {
        int t{-1};
        switch (m)
        {
        case 'k': // up
            if (index - dimension >= 0)
            {
                t = a[index - dimension];
                a[index - dimension] = a[index];
                a[index] = t;
                index -= dimension;
            }
            else
            {
                cout << "You can't move up.";
            }
            break;
        case 'i': // down
            if (index + dimension < size)
            {
                t = a[index + dimension];
                a[index + dimension] = a[index];
                a[index] = t;
                index += dimension;
            }
            else
            {
                cout << "You can't move down.";
            }
            break;
        case 'l': // left
            if ((index - 1) % (dimension) >= 0)
            {
                t = a[index - 1];
                a[index - 1] = a[index];
                a[index] = t;
                index -= 1;
            }
            else
            {
                cout << "You can't move left.";
            }
            break;
        case 'j': // right
            if ((index + 1) % dimension > 0)
            {
                t = a[index + 1];
                a[index + 1] = a[index];
                a[index] = t;
                index += 1;
            }
            else
            {
                cout << "You can't move right.";
            }
            break;
        default:
            cout << "Invalid move. Up(i), Down(k), Left(j), Right(l)";
        }

        cout << "\n";

        if (t != -1)
            display();
    }

    void display()
    {
        system("clear");

        for (int i{0}; i < size; i++)
        {
            cout << "  |  " << a[i];

            if ((i + 1) % dimension == 0)
                cout << " |\n";
        }
    }
};

// SOLUTION
int main()
{
    char move{};

    Puzzle *puzzle = new Puzzle(3);
    puzzle->initialize();
    puzzle->shuffle();
    puzzle->display();

    while (!puzzle->solved())
    {
        cin >> move;
        puzzle->move(move);
    }

    delete puzzle;

    cout << "All complete. Congratulations!";

    return 0;
}