/***************************
 * Name        : shortestpaths.cpp
 * Author      : Nicholas Mtengwa
 * Date        : December 8, 2022
 * Description : Shortest Path
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 **************************/
 #include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

#define nV 4
#define INF 999

using namespace std;

int findMaxEdge(string input)
{
    int space = 0;
    int length = input.size();
    for(int i=4; i < length; i++)
        space++;
    return space;
}

void check(vector<string> input, string line, int index)
{
    int i = 0;
    bool result = true;
    for(auto obj = input.begin(); obj != input.end(); )
    {
        i++;
        obj++;
        if((i-1)==index)
            continue;
        if(line[0] == input[i-1][2])
        {
            for(int k=4; k < (int)input[i-1].length(); k++)
            {
                cout << input[i-1][k];
                result = false;
            }
            break;
        }
    }
    if(result)
        cout << "-";
}

void distanceMatrix(vector<string> input, int no_of_vertices)
{
    int spaces = 0;
    for(auto obj = input.begin(); obj != input.end(); )
    {
        int Newspaces = findMaxEdge(*obj);
        if(spaces < Newspaces)
            spaces = Newspaces;
        obj++;
    }
    cout << "Distance matrix:" << endl << " ";
    for(int i=0; i < no_of_vertices; i++)
    {
        for(int j=1; j <= spaces; j++)
            cout << " ";
        cout << char(65+i);
    }
    for(int i=0; i < no_of_vertices; i++ )
    {
        cout << endl << char(65+i);
        for(int j=0; j < no_of_vertices; j++)
        {
            int minus = 0;
            for(int k=4; k < (int)input[j].length(); k++)
                minus++;
            for(int p=1; p <= spaces - minus + 1; p++)
                cout << " ";
            for(int k=4; k < (int)input[j].length(); k++)
            {
                if(i==j)
                {
                    cout << "0";
                    break;
                }
                else
                    //check(input, input[j],j);
                    cout << input[j][k];
            }
        }
    }
    cout << endl << endl;
}

void pathLengths(vector<string> input, int no_of_vertices)
{
    int spaces = 0;
    for(auto obj = input.begin(); obj != input.end(); )
    {
        int Newspaces = findMaxEdge(*obj);
        if(spaces < Newspaces)
            spaces = Newspaces;
        obj++;
    }
    cout << "Path lengths:" << endl << " ";
    for(int i=0; i < no_of_vertices; i++)
    {
        for(int j=1; j <= spaces; j++)
            cout << " ";
        cout << char(65+i);
    }
    for(int i=0; i < no_of_vertices; i++ )
    {
        cout << endl << char(65+i);
        for(int j=0; j < no_of_vertices; j++)
        {
            int minus = 0;
            for(int k=4; k < (int)input[j].length(); k++)
                minus++;
            for(int p=1; p <= spaces - minus + 1; p++)
                cout << " ";
            for(int k=4; k < (int)input[j].length(); k++)
            {
                if(i==j)
                {
                    cout << "0";
                    break;
                }
                else
                    //check(input, input[j],j);
                    cout << input[j][k];
            }
        }
    }
    cout << endl << endl;

}

void intermediateVertices(vector<string> input, int no_of_vertices)
{
    int spaces = 0;
    for(auto obj = input.begin(); obj != input.end(); )
    {
        int Newspaces = findMaxEdge(*obj);
        if(spaces < Newspaces)
            spaces = Newspaces;
        obj++;
    }
    cout << "Intermediate vertices:" << endl << " ";
    for(int i=0; i < no_of_vertices; i++)
    {
        for(int j=1; j <= spaces; j++)
            cout << " ";
        cout << char(65+i);
    }
    for(int i=0; i < no_of_vertices; i++ )
    {
        cout << endl << char(65+i);
        for(int j=0; j < no_of_vertices; j++)
        {
            int minus = 0;
            for(int k=4; k < (int)input[j].length(); k++)
                minus++;
            for(int p=1; p <= spaces - minus + 1; p++)
                cout << " ";
            for(int k=4; k < (int)input[j].length(); k++)
            {
                if(i==j)
                {
                    cout << "0";
                    break;
                }
                else
                    //check(input, input[j],j);
                    cout << input[j][k];
            }
        }
    }
    cout << endl << endl;
    for (int i =0; i<no_of_vertices; i++)
    {
        cout << char(i+65) << " -> " << char(65+i);
        cout << ", distance: " << 0;
        cout << ", path: " << char(65+i) << endl;
    }
}

int validateLine(string input, int no_of_vertices, int line_no)
{
    if(input.length() < 4)
    {
        cout << "Error: Invalid edge data '" << input <<"' on line " << line_no << ".";
        return 0;
    }
    return 1;
}

int validateEdges(string input, int no_of_vertices, int line_no)
{
    if(!(input[4] > 48 && input[4] < 58))
    {
        if(input.length() < 6)
        {
            cout << "Error: Invalid edge weight '" << input[4] << "' on line " << line_no << ".";
        }
        else
        {
            int num = input.length();
            cout << "Error: Invalid edge weight '";
            for (int i=4; i < num ; i++ )
                cout << input[i];
            cout << "' on line " << line_no << ".";
        }
        return 0;
    }
    return 1;
}

int validateVertices(string input, int no_of_vertices, int line_no)
{
    bool one = false, two = false;
    for(int i=65; i < (65 + no_of_vertices); i++)
    {
        if(input[0] == i)
        {
            one = true;
        }
        if(input[2] == i)
        {
            two = true;
        }
    }
    if(!one)
    {
        if(input[1]!= ' ')
        {
            cout << "Error: Starting vertex '";
            for (int i=0; input[i] != ' '; i++ )
                cout << input[i];
            cout << "' on line " << line_no << " is not among valid values A-" << char(64+no_of_vertices) << ".";
        }
        else
            cout << "Error: Starting vertex '" << input[0] << "' on line " << line_no << " is not among valid values A-" << char(64+no_of_vertices) << ".";
        return 0;
    }
    if(!two)
    {
        if(input[3]!= ' ')
        {
            cout << "Error: Ending vertex '";
            for (int i=2; input[i] != ' '; i++ )
                cout << input[i];
            cout << "' on line " << line_no << " is not among valid values A-" << char(64+no_of_vertices) << ".";
        }
        else
            cout << "Error: Ending vertex '" << input[2] << "' on line " << line_no << " is not among valid values A-" << char(64+no_of_vertices) << ".";
        return 0;
    }
    return 1;
}

int validateData(vector<string> input, int no_of_vertices)
{
    int line_no=2;
    bool yes = true;
    for(auto obj = input.begin(); obj != input.end(); )
    {
        if(yes)
        {
            if(validateLine(*obj, no_of_vertices, line_no) == 0)
            {
                yes = false;
            }
            obj++;
            line_no++;
        }
        else
            break;
    }
    if(!yes)
    {
        return 0;
    }
    line_no = 2;
    for(auto obj = input.begin(); obj != input.end(); )
    {
        if(yes)
        {
            if(validateVertices(*obj, no_of_vertices, line_no) == 0)
            {
                yes = false;
            }
            obj++;
            line_no++;
        }
    }
    if(!yes)
    {
        return 0;
    }
    line_no = 2;
    for(auto obj = input.begin(); obj != input.end(); )
    {
        if(yes)
        {
            if(validateEdges(*obj, no_of_vertices, line_no) == 0)
            {
                yes = false;
            }
            obj++;
            line_no++;
        }
    }
    if(!yes)
        return 0;
    else
        return 1;
}

void printMatrix(int matrix[][nV]) {
  for (int i = 0; i < nV; i++) {
    for (int j = 0; j < nV; j++) {
      if (matrix[i][j] == INF)
        printf("%4s", "-");
      else
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}
// Implementing floyd warshall algorithm
void floydWarshall(int graph[][nV]) {
  int matrix[nV][nV], i, j, k;

  for (i = 0; i < nV; i++)
    for (j = 0; j < nV; j++)
      matrix[i][j] = graph[i][j];

  // Adding vertices individually
  for (k = 0; k < nV; k++) {
    for (i = 0; i < nV; i++) {
      for (j = 0; j < nV; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  printMatrix(matrix);
}

void showData()
{
    cout << "Distance matrix:" << endl << "  ";
    cout << char(65) << endl;
    cout << char(65) << " " << 0 << endl << endl;

    cout << "Path lengths:" << endl;
    cout << "  " << char(65) << endl;
    cout << char(65) << " " << 0 << endl << endl;

    cout << "Intermediate vertices:" << endl;
    cout << "  " << char(65) << endl;
    cout << char(65) << " -" << endl << endl;

    cout << char(65) << " -> " << char(65);
    cout << ", distance: " << 0;
    cout << ", path: " << char(65) << endl;
}

int main(int argc, const char *argv[])
{
    // Make sure the right number of command line arguments exist.
    if (argc != 2) {
        cerr << "Usage: ./shortestpaths <filename>" << endl;
        return 1;
    }
    // Create an ifstream object.
    ifstream input_file(argv[1]);
    // If it does not exist, print an error message.
    if (!input_file) {
        cerr << "Error: Cannot open file '" << argv[1] << "'." << endl;
        return 1;
    }

    //readingFile(input_file,argv[1]);

    // Add read errors to the list of exceptions the ifstream will handle.
    input_file.exceptions(ifstream::badbit);
    string line;
    try
    {
        // Use getline to read in a line.
        // See http://www.cplusplus.com/reference/string/string/getline/
        vector<string> input = {};
        int no_of_vertex = 0;
        bool oneTime = true;
        while (getline(input_file, line))
        {
            if(oneTime)
            {
                if(line[0] < 58 && line[0] > 48)
                    no_of_vertex = stoi(line);
                else
                {
                    cout << "Error: Invalid number of vertices '" << line << "' on line 1.";
                    return 0;
                }
                oneTime=false;
            }
            else
            {
                input.push_back(line);
                if(validateData(input, no_of_vertex) == 0)
                return 0;
            }
        }
        if(no_of_vertex < 2)
            showData();
        else
        {
            distanceMatrix(input, no_of_vertex);
            pathLengths(input, no_of_vertex);
            intermediateVertices(input, no_of_vertex);

        }
        // close the file.
        input_file.close();
    } catch (const ifstream::failure &f) {
        cerr << "Error: An I/O error occurred reading '" << argv[1] << "'.";
        return 1;
    }

    return 0;

}
