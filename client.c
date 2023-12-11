#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<pthread.h>
#include<unistd.h>

int r1,c1,r2,c2;
int mat1[100][100],mat2[100][100],result[100][100];


void display(int mat[][100],int r,int c){
        for(int i=0;i<r;i++){
                for (int j=0;j<c;j++){

                        printf("%d\t",mat[i][j]);
                }
                printf("\n");
        }
https://github.com/Anjithaelxsi/matrix-multiplication.git}

void fill(int mat[][100],int r,int c){
        for (int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                        scanf("%d",&mat[i][j]);
                }
        }
}

int main(){

        int client_sock=socket(AF_INET,SOCK_STREAM,0);
        struct sockaddr_in serveraddr;
        serveraddr.sin_family=AF_INET;
        serveraddr.sin_port=htons(1245);
        serveraddr.sin_addr.s_addr=INADDR_ANY;

        int connection_status=connect(client_sock,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
        if (connection_status==-1)
        {
                printf("error");
        }


        printf("enter the number of rows of first matrix\n");
        scanf("%d",&r1);
        send(client_sock,&r1,sizeof(r1),0);
        printf("enter the number of columns in first matrix\n");
        scanf("%d",&c1);
        send(client_sock,&c1,sizeof(c1),0);
        printf("enter Mat1 elements\n");
        fill(mat1,r1,c1);
        send(client_sock,mat1,sizeof(mat1),0);
        printf("matrix1\n");
        display(mat1,r1,c1);

         printf("enter the number of rows of sec matrix\n");
        scanf("%d",&r2);
        send(client_sock,&r2,sizeof(r2),0);
        printf("enter the number of columns in sec matrix\n");
        scanf("%d",&c2);
        send(client_sock,&c2,sizeof(c2),0);
        printf("enter Mat2 elements\n");
        fill(mat2,r2,c2);
        send(client_sock,mat2,sizeof(mat2),0);
        printf("matrix2\n");
        display(mat2,r2,c2);
   if (c1 != r2)
        {
                printf("Invalid dimensions for matrix multiplication.\n");
                return 0;
        }



        recv(client_sock,result,sizeof(result),0);

        printf("the resulted  matrix is\n");
        display(result,r1,c2);



        close(client_sock);



        return 0;
}

                                                                                                                                                                                          91,0-1        Bot

