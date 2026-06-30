#include <iostream>

using namespace std;

int main()
{
    string ten[11] =
    {
        "Ha Noi",
        "Hai Duong",
        "Phu Ly",
        "Hung Yen",
        "Hai Phong",
        "Uong Bi",
        "Bac Giang",
        "Bac Ninh",
        "Thai Nguyen",
        "Son Tay",
        "Hoa Binh"
    };

    int a[11][11];

    for(int i=0;i<11;i++)
    {
        for(int j=0;j<11;j++)
        {
            a[i][j]=0;
        }
    }

    a[0][1]=6;
    a[1][0]=6;

    a[0][2]=5;
    a[2][0]=5;

    a[0][7]=3;
    a[7][0]=3;

    a[0][8]=7;
    a[8][0]=7;

    a[0][9]=4;
    a[9][0]=4;

    a[0][10]=8;
    a[10][0]=8;

    a[1][3]=2;
    a[3][1]=2;

    a[1][4]=5;
    a[4][1]=5;

    a[2][3]=2;
    a[3][2]=2;

    a[4][5]=4;
    a[5][4]=4;

    a[5][6]=2;
    a[6][5]=2;

    a[6][7]=2;
    a[7][6]=2;

    a[7][5]=3;
    a[5][7]=3;

    cout<<"Danh sach thanh pho"<<endl;

    for(int i=0;i<11;i++)
    {
        cout<<i<<" "<<ten[i]<<endl;
    }

    cout<<endl;

    cout<<"Ma tran trong so"<<endl;

    for(int i=0;i<11;i++)
    {
        for(int j=0;j<11;j++)
        {
            cout<<a[i][j]<<" ";
        }

        cout<<endl;
    }

    return 0;
}