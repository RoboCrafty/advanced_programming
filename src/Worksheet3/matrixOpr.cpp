#include <iostream>

// The main task here was to use this file from wks2 and change it to support any input types instead of just ints
// This was done using the templates




template <typename T>
void printVector(std::vector<T>& v)
{
    std::cout << "Vector is: \n" <<  "{ ";
    for(int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << "}" << std::endl;
}

template <typename T>
void fillMatrix(std::vector<std::vector<T>>& m, T& dim)
{
    m.resize(dim);   
    T x; // 

    // Fill row by row
    for (int i = 0; i < dim; i++)
    {
        std::cout << "Enter values for row " << i << " and Press enter after each. " << std::endl;
        for (int j = 0; j < dim; j++)
        {
            std::cin >> x;
            m[i].push_back(x);
        }
    }

    // Print Matrix
    std::cout << "Recorded Matrix: " << std::endl;
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            std::cout << m[i][j] << "   ";
        }
        std::cout << std::endl;
    }
}

// Multiply matrix and vector
template <typename T>
std::vector<T>  operator* (std::vector<std::vector<T>>& m, std::vector<T>& v)
{
    std::vector<T> q; // temp vector
    q.resize(v.size());
    for(int i = 0; i < v.size(); i++)
    {
        
        for(int j = 0; j < m.size(); j++)
        {
            q[i] += m[i][j] * v[j];
        }
    }
    return q;
}

int main ()
{
    std::vector<double> v;
    double x;
    std::cout << "Enter elements for vector. Press enter after each. " << std::endl;

    while(std::cin >> x)
    {
        v.push_back(x);
    }
    std::cin.clear();
    std::cin.ignore();

    printVector(v);


    std::vector<std::vector<double>> m;
    std::cout << "\nVector size is: "<< v.size() << "\n\nHence, matrix size will be "<< v.size() << "x" << v.size()<< std::endl;
    double dim = v.size();
    
    fillMatrix(m, dim);

    auto res = m * v;

    printVector(res);

}