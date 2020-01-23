#include <iostream>
#include <stdio.h>

using namespace std;

void IniciarMatriz(char [][20],int);
void MostrarMatriz(char [][20], int);
void MovimientoAmazona(char [][20],int ,int,int);
bool posCorrecta(char [][20],int,int);

int n;
char matriz[20][20];

//Poner en 0 la matriz nxn
void IniciarMatriz(char matriz[20][20],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			matriz[i][j]='0';
		}
	}
}

//Mostrar la motriz nxn
void MostrarMatriz(char matriz[20][20], int n){
    cout << "\n";
    cout << "Las 'M' representan a las amazonas\n" << endl << " " <<endl;
	for (int i=0;i<n; i++){
    	for(int j=0;j<n;j++){
    		    if(matriz[i][j]=='X'){
    		    matriz[i][j] = '0';    
    		}
    			cout<<matriz[i][j]<<" ";
		}
		cout<<endl;
    }
    cout<<endl;
}

//Movimiento Reina+Caballo
void MovimientoAmazona(char matriz[20][20],int f,int c, int n){
	int i=f;
	int j=c;
	while(i>=0&&j>=0){		//Diagonal superior izquierda
		matriz[i-1][j-1]='X';	//Si es -1 se come la M
		i--;
		j--;
	}
	i=f;j=c;
	while(i<n&&j<n){		//Diagonal inferior derecha
		matriz[i+1][j+1]='X';
		i++;
		j++;
	}
	i=f;j=c;
	while(i>=0&&j<n){		//Diagonal superior derecha
		matriz[i-1][j+1]='X';
		i--;
		j++;
	}
	i=f;j=c;
	while(i<n&&j>=0){		//Diagonal superior derecha
		matriz[i+1][j-1]='X';
		i++;
		j--;
	}
	i=f;j=c;
	while(i>=0){		//Columna superior
		matriz[i-1][j]='X';
		i--;	
	}
	i=f;j=c;
	while(i<n){		//Columna inferior
		matriz[i+1][j]='X';
		i++;	
	}
	i=f;j=c;
	while(j>=0){		//Línea izquierda
		matriz[i][j-1]='X';
		j--;	
	}
	i=f;j=c;
	while(j<n){		//Línea derecha
		matriz[i][j+1]='X';
		j++;	
	}
	
	i=f-2;j=c-2;		//Pone las posiciones en la esquina sup izquierda para calcular el cuadrado de la muerte
	while(i<(f+3)){
		while(j<(c+3)){
			//if( i!=(f+1) || (j!=c+1 ) ){
			if( matriz[i][j] != matriz[f][c] ){
				matriz[i][j]='X';
			}
			j++;
		}
		j=c-2;
	i++;
	} 
	
}

bool posCorrecta(char matriz[20][20],int x,int y){
	bool s = true;
	if ('X' == matriz[x][y] || 'M' == matriz[x][y]){
		s = false;
	}
	return s;
	
}


int main()
{
	int am, z=0;
	cout << "Crear matriz nxn (max 20)"<< endl;
	cout <<"n: ";
	cin >> n;
	IniciarMatriz(matriz,n);
	cout<< "ingrese el numero de amazonas que quiere colocar: ";
	cin >> am;
	while(z<am){
		bool recorrer = true; 
		for(int j=0;j<n && recorrer;j++){
		    for(int k=0; k<n && recorrer;k++){
			if(posCorrecta(matriz,j,k)){
				matriz[j][k]='M';
				MovimientoAmazona(matriz,j,k,n);
				z++;
				recorrer = false;
			}
		}	
	}
}

MostrarMatriz(matriz,n);

return 0;
}
