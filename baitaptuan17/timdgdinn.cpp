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
    int dauTien;
    int dich;
    cout << "Nhap dinh bat dau: ";

    cin >> dauTien;

    cout << "Nhap dinh dich: ";

    cin >> dich;

    int kc[11];
    int daXet[11];
    int cha[11];

    for(int i=0;i<11;i++)
    {
        kc[i]=100;
        daXet[i]=0;
        cha[i]=-1;
    }

    kc[dauTien]=0;

    for(int k=0;k<11;k++)
    {
        int u=-1;
        int minValue=100;

        for(int i=0;i<11;i++)
        {
            if(daXet[i]==0 && kc[i]<minValue)
            {
                minValue=kc[i];
                u=i;
            }
        }

        if(u==-1)
        {
            break;
        }

        daXet[u]=1;

        for(int v=0;v<11;v++)
        {
            if(a[u][v]!=0)
            {
                if(daXet[v]==0 && kc[u]+a[u][v]<kc[v])
                {
                    kc[v]=kc[u]+a[u][v];
                    cha[v]=u;
                }
            }
        }
    }

    cout<<endl;
    cout<<"Duong di ngan nhat tu"
         << ten[dauTien]
        << " -> "
        << ten[dich]
        <<endl;

    int duong[20];
    int dem=0;
    int x=dich;

    while(x!=-1)
    {
        duong[dem]=x;
        dem++;
        x=cha[x];
    }

    for(int i=dem-1;i>=0;i--)
    {
        cout<<ten[duong[i]];

        if(i!=0)
        {
            cout<<" -> ";
        }
    }

    cout<<endl;
    cout<<"Tong trong so: "<<kc[dich]<<endl;
        cout<<endl;
    cout<<"PRIM"<<endl;

    int key[11];
    int parent[11];
    int chon[11];

    for(int i=0;i<11;i++)
    {
        key[i]=100;
        parent[i]=-1;
        chon[i]=0;
    }

    key[dauTien]=0;

    for(int dem=0;dem<11;dem++)
    {
        int u=-1;
        int minValue=100;

        for(int i=0;i<11;i++)
        {
            if(chon[i]==0 && key[i]<minValue)
            {
                minValue=key[i];
                u=i;
            }
        }

        if(u==-1) break;

        chon[u]=1;

        for(int v=0;v<11;v++)
        {
            if(a[u][v]!=0)
            {
                if(chon[v]==0 && a[u][v]<key[v])
                {
                    key[v]=a[u][v];
                    parent[v]=u;
                }
            }
        }
    }

    int cay[11][11];

    for(int i=0;i<11;i++)
    {
        for(int j=0;j<11;j++)
        {
            cay[i][j]=0;
        }
    }

    for(int i=1;i<11;i++)
    {
        cay[i][parent[i]]=a[i][parent[i]];
        cay[parent[i]][i]=a[i][parent[i]];
    }

    cout<<"Ma tran cay khung PRIM"<<endl;

    for(int i=0;i<11;i++)
    {
        for(int j=0;j<11;j++)
        {
            cout<<cay[i][j]<<" ";
        }

        cout<<endl;
    }

    cout<<endl;
    cout<<"KRUSKAL"<<endl;

    struct Edge
    {
        int u;
        int v;
        int w;
    };

    Edge e[30];

    int m=0;

    for(int i=0;i<11;i++)
    {
        for(int j=i+1;j<11;j++)
        {
            if(a[i][j]!=0)
            {
                e[m].u=i;
                e[m].v=j;
                e[m].w=a[i][j];
                m++;
            }
        }
    }

    for(int i=0;i<m-1;i++)
    {
        for(int j=i+1;j<m;j++)
        {
            if(e[i].w>e[j].w)
            {
                Edge t=e[i];
                e[i]=e[j];
                e[j]=t;
            }
        }
    }

    int root[11];

    for(int i=0;i<11;i++)
    {
        root[i]=i;
    }

    int cay2[11][11];

    for(int i=0;i<11;i++)
    {
        for(int j=0;j<11;j++)
        {
            cay2[i][j]=0;
        }
    }

    for(int i=0;i<m;i++)
    {
        int r1=root[e[i].u];
        int r2=root[e[i].v];

        if(r1!=r2)
        {
            cay2[e[i].u][e[i].v]=e[i].w;
            cay2[e[i].v][e[i].u]=e[i].w;

            for(int j=0;j<11;j++)
            {
                if(root[j]==r2)
                {
                    root[j]=r1;
                }
            }
        }
    }

    cout<<"Ma tran cay khung KRUSKAL"<<endl;

    for(int i=0;i<11;i++)
    {
        for(int j=0;j<11;j++)
        {
            cout<<cay2[i][j]<<" ";
        }

        cout<<endl;
    }
    return 0;
}