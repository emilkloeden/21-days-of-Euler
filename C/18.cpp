#include <iostream> // Preprocesser declaration to enable output to stdio
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
using namespace std; // Without this I'd have to write //std.cout

// Modify 2D Vector Matrix and print out Max path
int findMaxPath (vector<vector<int> > & v)
{
    // Iterate through vectors from bottom to top
    for (unsigned int i = (v.size() - 1); i > 0; i--)
    {
        vector<int> current_vector = v[i];
        vector<int> next_vector = v[i-1];
        vector<int> combined_vector;

        // Iterate through cells left to right
        for (unsigned int j = 0; j < (current_vector.size() - 1) ; j++)
        {
            int current_cell = current_vector[j];
            int next_cell = current_vector[j+1];
            int shared_cell = next_vector[j];
            int max_cell = current_cell > next_cell ? current_cell + shared_cell : next_cell + shared_cell;
                
            combined_vector.push_back(max_cell);
        }
        v.pop_back();
        v.pop_back();
        v.push_back(combined_vector);
    }
    return v[0][0];
}

vector<int> parseLine(string line)
{
    vector<int> tokens;
    istringstream ss(line);

    // Split lines by ' ' delimeter
    while (!ss.eof())
    {
        string x;
        getline(ss, x, ' ');

        // Convert string to int
        int y = atoi(x.c_str());

        // Push int to vector
        tokens.push_back(y);
    }
    return tokens;

}

vector<vector<int> > parseFile(string filename)
{
    // Open file
    string line;
    ifstream myfile;
    myfile.open(filename.c_str());
    vector<vector<int> > lines;
    
    // Split file by line
    while (getline (myfile, line))
    {
        // Parse lines
        vector<int> cells = parseLine(line);

        // Push line vectors into lines 2D vector
        lines.push_back(cells);
    }

    // Close file
    myfile.close();

    // return statement
    return lines;
}



int main(int argc, char* argv[])
{
    // Accept filename as a command-line parameter or use '18.txt' by default 
    string filename = "../18.txt";

    if (argc >= 2)
    {
        filename = argv[1]; 
    }

    vector<vector<int> > triangle = parseFile(filename);

    // Print answer
    int answer = findMaxPath(triangle);
    cout << answer << endl;
    // Obligatory return statement
    return 0;
}

