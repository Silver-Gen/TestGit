#include <iostream>
using namespace std;
class matrix
{
    public:
        int m,n;
        int **mat;
        matrix(int a,int b)
        {
            m=a;
            n=b;
            mat=(int**)malloc(m*sizeof(int*));
            for(int i=0;i<m;i++)
                mat[i]=(int*)malloc(n*sizeof(int));
        }
        void input()
        {
            for(int i=0;i<m;i++)
                for(int j=0;j<n;j++)
                    cin>>mat[i][j];
        }
        void display()
        {
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<mat[i][j];
                    if(j!=(n-1))
                        cout<<" ";
                }
                cout<<endl;
            }
        }
        matrix friend operator +(matrix,matrix);
        matrix friend operator -(matrix,matrix);
};
matrix operator +(matrix a,matrix b)
{
    int m,n;
    m=a.m;
    n=a.n;
    matrix temp(m,n);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            temp.mat[i][j]=a.mat[i][j]+b.mat[i][j];
    return temp;
}
matrix operator -(matrix a,matrix b)
{
    int m,n;
    m=a.m;
    n=a.n;
    matrix temp(m,n);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            temp.mat[i][j]=a.mat[i][j]-b.mat[i][j];
    return temp;
}
int main()
{
    int m,n;
    char c;
    cin>>m;
    cin>>n;
    matrix mat1(m,n);
    mat1.input();
    cin>>m;
    cin>>n;
    matrix mat2(m,n);
    mat2.input();
    matrix matres(m,n);
    cin>>c;
    if(c=='+')
        matres=mat1+mat2;
    if(c=='-')
        matres=mat1-mat2;
    matres.display();
    return 0;
}
