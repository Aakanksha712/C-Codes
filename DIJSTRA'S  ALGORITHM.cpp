#include <iostream>
using namespace std;

class algorithm
{
   public:
       int vtx,edg;
       int weight,n,i,j,k;
       int maximum;

       void dijstra(); //function
};

void algorithm::dijstra()

{
      cout<<"\nEnter number of endpoints [vertex]\t";
      cin>>vtx;
      cout<<"\nEnter the number of edges\t";
      cin>>edg;

      int graph[vtx][vtx];       //graph or adjacency Matrix
      int varr[vtx];             //visited array
      string arr[vtx];          //Label ARRAY
      string output[vtx];       //To store output at last
      string parent[vtx];      //Keep track of previous vertex
      int dist[vtx];           //distance array
      char pt1,pt2;
      maximum=9999;
      char var;                //It act as flag value
      string source;          // source vertex

     for(i=0;i<vtx;i++)
        {
           cout<<"\nEnter node\t";
           cin>>arr[i];
           varr[i]=0; //Mark all nodes as unvisited
        }
     for(i=0;i<vtx;i++)
        {
              for(j=i;j<vtx;j++)
                  {
                      cout<<"\nIs there any edge between "<<arr[i]<<" to "<<arr[j]<<" ";
                      cin>>var;
                      if(var=='y') //if var=y then accept value else there is no edge
                          {
                               cout<<"\nEnter weight\t";
                               cin>>graph[i][j];
                               graph[j][i]=graph[i][j];
                           }
                      else
                           {
                               graph[i][j]=maximum;
                               graph[j][i]=graph[i][j];
                           }

                }

        }
        cout<<"\nEnter source\t"; //source is entered
        cin>>source;
    int curr,start;
    int dis=9999;
        for(i=0;i<vtx;i++)

            {

                if(arr[i]==source) //loop to find index of source
                    {
                        curr=i;
                        break;
                    }

            }
    for(i=0;i<vtx;i++)

      {
          dist[i]=graph[curr][i]; //dist[] array is the distance of each vertex from source
          parent[i]=arr[curr]; //parent[] is previous vertex
      }
  varr[curr]=1; //mark source as visited
  dist[curr]=0; //Its shortest distance from source
  parent[curr]=source; //parent of source
  start=curr; //store the index of source
  n=1; //counter
  while(n<(vtx-1))

    {
      dis=maximum; for(i=0;i<vtx;i++) //Loop to find out nearest neighbour

         {

            if(dist[i]<dis && varr[i]==0)
                 {
                    dis=dist[i];
                     curr=i;
                 }

        }
     varr[curr]=1; //Mark it as visited

     //Loop to find better path if exist
  for(i=0;i<vtx;i++)

       {

           if(varr[i]==0) //if vertex is unvisited

              {
               if((dis+graph[curr][i])<dist[i])
                      // if its distance is less than previous distance
                  {
                       dist[i]=dis+graph[curr][i]; //update distance
                       parent[i]=arr[curr]; //update parent
                  }

              }

        }
      n++; //increment counter
    }
//Loop to display OUTPUT
int z;
   cout<<"\nSHORTEST DISTANCE AND PATH\n\n";
   cout<<"\n\n**"<<source<<"**"<<"\ndistance = "<<dist[start];
   cout<<" path\t"<<source<<" --> "<<source<<endl;
for(i=0;i<vtx;i++)

   {
        if(i!=start)
           {

             z=0;
             cout<<"\n\n**"<<arr[i]<<"**\nDISTANCE = "<<dist[i]<<"\nPATH\t";
             j=i;
             do
                {
                  output[z]=parent[j]; //Storing previous vertices
                  z++;
                  for(k=0;k<vtx;k++)

                    {
                        if(parent[j]==arr[k])
                         j=k;
                    }

                 }while(j!=start);
                for(int m=z-1;m>=0;m--) //Loop to print path
                   {
                       cout<<output[m]<<" --> ";
                   }
               cout<<arr[i];
               cout<<endl;
              }
      }
   cout<<endl;

 }

int main()
{
 algorithm a;
 int opt;
 while(true)
   {
        cout<<"\nDo you want to execute Dijstra's Algorithm ? \t";
        cout<<"\n1 - YES\n0 - NO\t";
        cin>>opt;
        if(opt==0)
              break;
        else
            a.dijstra();
   }

}
