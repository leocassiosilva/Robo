#include <stdio.h>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

#define ALTURA 20
#define LARGURA 20

void MoveEsquerda(int x);
void MoveDireita(int x);
void MoveCima(int y);
void MoveBaixo(int y);
void ImprimeMapa(int px, int py);
void LimiteTabuleiro(int px, int py);

int px, py;
int rx, ry;
char ordem;
int continua = 1;
int x, y;
int l=0;
int vx[40];
int vy[40];


int main (void)
{
		
   srand(time(0));
	px = (rand() % (19 - 0+1) + 0);
	py = (rand() % (19 - 0+1) + 0);
	rx = (rand() % (19 - 0+1) + 0);
	ry = (rand() % (19 - 0+1) + 0);
	
	ImprimeMapa(px, py);
	while (continua)
	{	
		vx[l]=px; 
		vy[l]=py;
		l++;

		int dx = (px-rx); 
		int dy = (py-ry);

		if (abs(dx) > abs(dy))
		{
			if (dx >= 0)
			{
				px--;
			}else{
				px++;
			}
		}else {	
			if(dy >= 0){
				py--;
			}else{
				py++;
			}
			
		}
	
		cout <<dx <<endl;
		cout <<dy <<endl;


		ordem = getchar();
		//system("cls"); // aletar para linux //system("clear");
		/*switch(ordem)
		{
			case 'a': case 'A': 
				MoveEsquerda(px);
				ImprimeMapa(px, py);
				break;
			case 'd': case 'D': 
				MoveDireita(px);
				ImprimeMapa(px, py);
				break;
			case 'w': case 'W': 
				MoveCima(py);
				ImprimeMapa(px, py);
				break;
			case 's': case 'S': 
				MoveBaixo(py);
				ImprimeMapa(px, py);
				break;
			case 'q': case 'Q': 
				continua = 0;
				break;

		}*/

		ImprimeMapa(px, py);
		
		cout << ordem << " " << px << " " << py << " " << "\n";
		LimiteTabuleiro(px,py);

		if ((px == rx) && (py==ry))
		{
			cout <<"O Rato foi comido" <<endl;
			continua=0;
		}
			
	}
	return 1;
}

void ImprimeMapa(int px, int py)
{
	//char i = -2; // Comida;
	//char predador = -28;
	
	int x, y;
	for (y = 0; y < ALTURA; y++)
	{
		for (x = 0; x < LARGURA; x++)
		{
			int cont = 0;
			for (int i = 0; i < 40; ++i)
			{
				if ((vx[i] == x && vy[i]==y) && !(vx[i] == 0 && vy[i] == 0))
				{
					cout<< " * ";
					cont = 1;
					break;
				}
			}

			if( cont == 0){

				if ((px == x) && (py == y)) 
				{
					cout << " R ";
				}else if((rx == x) && (ry == y)){
					cout << " @ ";
				}
				else
				{
					cout << " + ";
				}
			}
		}
		cout << endl;
	}

	ofstream escreve; 
	escreve.open("robo.txt");

	for (y = 0; y < ALTURA; y++)
	{
		for (x = 0; x < LARGURA; x++)
		{
			int cont = 0;
			for (int i = 0; i < 40; ++i)
			{
				if ((vx[i] == x && vy[i]==y) && !(vx[i] == 0 && vy[i] == 0))
				{
					escreve<< " * ";
					cont = 1;
					break;
				}
			}

			if( cont == 0){

				if ((px == x) && (py == y)) 
				{
					escreve << " R ";
				}else if((rx == x) && (ry == y)){
					escreve << " @ ";
				}
				else
				{
					escreve << " + ";
				}
			}
		}
		escreve << "\n";
	}

}

void LimiteTabuleiro(int px,int py)
{
		if (!(px > 0 || px < LARGURA-1 || py > 0 || py < ALTURA-1))
			 cout << "LIMITE DO TABULEIRO!! \n";
}

/*void MoveEsquerda(int x)
{
	if (x > 0) 
		px = x - 1;
	else
		cout << "LIMITE DO TABULEIRO!! \n";		
}
void MoveDireita(int x)
{
	if (x < 19) 
		px = x + 1;
	else 
		cout << "LIMITE DO TABULEIRO!! \n";	
}
void MoveCima(int y)
{
	if (y > 0) 
		py = y - 1;
	else
		cout << "LIMITE DO TABULEIRO!! \n";	
}
void MoveBaixo(int y)
{
	if (y < 19) 
		py = y + 1;
	else
		cout << "LIMITE DO TABULEIRO!! \n";	
}
*/

