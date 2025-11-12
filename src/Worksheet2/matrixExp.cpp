#include <iostream>
#include "/opt/homebrew/opt/boost/include/boost/math/special_functions/factorials.hpp"

// This was me tinkering to find matrix exponentials as I had that in advanced control as part of the first chapter in basic concepts


void printVector(std::vector<int>& v)
{
    std::cout << "Vector is: \n" <<  "{ ";
    for(int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << "}" << std::endl;
}

void fillMatrix(std::vector<std::vector<int>>& m, int& dim)
{
    // Initialize the matrix with proper dimensions
    m.resize(dim);
    for(int i = 0; i < dim; i++) {
        m[i].resize(dim, 0);  // Initialize each row with dim columns, filled with zeros
    }
    
    int x;
    // Fill row by row
    for (int i = 0; i < dim; i++)
    {
        std::cout << "Enter values for row " << i << " and Press enter after each. " << std::endl;
        for (int j = 0; j < dim; j++)
        {
            std::cin >> x;
            m[i][j] = x;  // Use direct assignment instead of push_back
        }
    }

}

void printMatrix(std::vector<std::vector<int>>& m)
{
    int dim = m.size();
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            std::cout << m[i][j] << "   ";
        }
        std::cout << std::endl;
    }
}

void multiplyMatrix(std::vector<std::vector<int>>& m, std::vector<std::vector<int>>& n)
{
     std::vector<std::vector<int>> q; // temp matrix
    q.resize(m.size());
    for(int i = 0; i < m.size(); i++)
    {
        
        for(int j = 0; j < m.size(); j++)
        {
            q[i][j] += m[i][j] * n[i][j];
        }
    }
    m = q;
}

void addMatrix(std::vector<std::vector<int>>& m, std::vector<std::vector<int>>& n)
{
     std::vector<std::vector<int>> q; // temp matrix
    q.resize(m.size());
    for(int i = 0; i < m.size(); i++)
    {
        
        for(int j = 0; j < m.size(); j++)
        {
            q[i][j] = m[i][j] + n[i][j];
        }
    }
    m = q;
}

int main ()
{

    int n = 3; //matrix size


    std::vector<std::vector<int>> m1;

    std::cout << "Matrix size is  "<< n << "x" << n << std::endl;
    int dim = n;

    int tn;
    std::cout << "Enter taylor series n: " << std::endl; 
    std::cin >> tn;
    
    fillMatrix(m1, dim);
    std::cout << "Matrix m1 is: " << std::endl;
    printMatrix(m1);


    // Initialize the matrix2 as a n x n array of 0.
    auto m2 = std::vector<std::vector<int>>(n, std::vector<int>(n,0));

    // Set the diagonal to be 1s
    for(unsigned int t = 0; t < n; t++)
        m2[t][t] = 1;

    // Print I Matrix
    std::cout << "Matrix m2 is: " << std::endl;
    printMatrix(m2);

    // Matrix exponential is calculated as follows:
    // exp(At) = I + ( A^1 *(t/1!) ) + ( A^2 *(t/2!) ) + ( A^n *(t/n!) )
    // where n is the length of the taylor series you want to calculate. 

    for (int i = 0; i < tn; i++)
    {
        addMatrix(multiplyMatrix)

        for(int j = 0; j < m.size(); j++)
        {
            
            for(int k = 0; k < m.size(); k++)
            {
                q[i][j] += m[i][j] * n[i][j];
            }
        }
    }
    multiplyMatrix(m1, m1);

    printMatrix(m1);

}