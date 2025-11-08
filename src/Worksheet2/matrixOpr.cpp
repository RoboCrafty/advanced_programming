#include <iostream>

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
    m.resize(dim);   
    int x; // 

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

void multiply(std::vector<std::vector<int>>& m, std::vector<int>& v)
{
    std::vector<int> q; // temp vector
    q.resize(v.size());
    for(int i = 0; i < v.size(); i++)
    {
        
        for(int j = 0; j < m.size(); j++)
        {
            q[i] += m[i][j] * v[j];
        }
    }
    v = q;
}

int main ()
{
    std::vector<int> v;
    int x;
    std::cout << "Enter elements for vector. Press enter after each. " << std::endl;

    while(std::cin >> x)
    {
        v.push_back(x);
    }
    std::cin.clear();
    std::cin.ignore();

    printVector(v);


    std::vector<std::vector<int>> m;
    std::cout << "\nVector size is: "<< v.size() << "\n\nHence, matrix size will be "<< v.size() << "x" << v.size()<< std::endl;
    int dim = v.size();
    
    fillMatrix(m, dim);

    multiply(m, v);

    printVector(v);

}