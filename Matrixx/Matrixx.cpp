
#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

class Matrix
{
    public:
        int lines;
        int cols;
        int** m;
        // конструктор  матрицы с нулями
        Matrix(int lines, int cols)
        {
            m = new int* [lines];
            m[0] = new int[cols * lines];
            for (int i = 1; i != cols; i++)
                m[i] = m[i - 1] + lines;
            this->lines = lines;
            this->cols = cols;
            for (int i = 0; i < this->lines; i++)
            {
                for (int j = 0; j < this->cols; j++)
                    m[i][j] = 0;
            }
        }
        // деконструктор матрицы
        ~Matrix()
        {

        }
        // вывод матрицы
        void Get()
        {
            for (int i = 0; i < lines; i++) 
            {
                for (int j = 0; j < cols; j++)
                    cout << m[i][j] << " ";
                cout << endl;
            }
        }
        // заполнение матрицы с консоли
        void ConSet()
        {
            for (int i = 0; i < lines; i++) 
            {
                for (int j = 0; j < cols; j++)
                    cin >> m[i][j];
            }
        }


};

bool operator==(Matrix  m1, Matrix  m2)
{
    if ((m1.cols != m2.cols) || (m2.lines != m1.lines))
        return false;
    for (int i = 0; i < m1.lines; i++)
    {
        for (int j = 0; j < m1.cols; j++)
        {
            if  (m1.m[i][j] != m2.m[i][j])
                return false;
        }
        return true;
    }
}

void operator * (Matrix  m1, int  a) // оператор меняет значения передаваемой матрицы
{

    for (int i = 0; i < m1.lines; i++)
    {
        for (int j = 0; j < m1.cols; j++)
        {
            m1.m[i][j] *= a;   
        }
   
    }
}

void operator / (Matrix  m1, int  a) // оператор меняет значения передаваемой матрицы
{

    for (int i = 0; i < m1.lines; i++)
    {
        for (int j = 0; j < m1.cols; j++)
        {
            m1.m[i][j] /= a;
        }

    }

}



int main()
{
    int c, l;
    cout << "Sizes" << endl;
    cin >> l;
    cin >> c;
    Matrix A(l, c);
    Matrix B(l, c);
    ifstream FA("FA.txt"); //чтение первой матрицы
    if (FA.is_open())
        cout << "FA is open" << endl;
    for (int i = 0; i < A.lines; i++)
    {
        for (int j = 0; j < A.cols; j++)
        {
            FA >> A.m[i][j];
        }
    }
    ifstream FB("FB.txt"); //чтение второй матрицы
    if (FB.is_open())
        cout << "FB is open" << endl;
    for (int i = 0; i < B.lines; i++)
    {
        for (int j = 0; j < B.cols; j++)
        {
            FB >> B.m[i][j];
        }
    }
    A.Get();
    cout << endl;
    B.Get();
    if (A == B) //проверка равенства
        cout << "True" << endl;
    else
        cout << "False" << endl;
    A * 3;
    cout << "A*3" << endl;
    A.Get();
    cout << "A/3" << endl;
    A / 3;
    A.Get();


}
