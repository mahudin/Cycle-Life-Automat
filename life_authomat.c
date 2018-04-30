#include <stdio.h>
#include <time.h>
int podaj_dane(int n);
int** tworz_tabela(int rozmiar);
void pokaz_tablice(int **tablica,int rozmiar);
void **realia_zyciowe(int **tabela,int rozmiar);
void reakcja_na_stan(int **tabela,int x,int y,int sasiedzi);
char martwa=176;
char zywa=219;
int main()
{
  int rozmiar,cyklmax,cykl=0,czas;
  int **tablica;
  printf("Witaj w symulatorze zycia komorek !\n");
  printf("\nPodaj rozmiar tablicy (np.15 to bedzie 15x15 itp.):");
  rozmiar=podaj_dane(rozmiar);
  printf("Podaj ilosc cykli zycia:");
  cyklmax=podaj_dane(cyklmax);
  printf("Podaj czas cyklu zycia(w sekundach):");
  czas=podaj_dane(czas);
  tablica=tworz_tabela(rozmiar);
  while(cykl++<cyklmax)
  {
  	pokaz_tablice(tablica,rozmiar);
  	realia_zyciowe(tablica,rozmiar);
  	sleep(czas);
  	system("cls");
  }
  return 0;
}

int podaj_dane(int n)
{
  	int a,b;
	poczatek:
	scanf("%d",&a);
	if(a>0) return a;
	else
	{
		printf("Bledne dane! Sproboj jeszcze raz.\n"); 
		goto poczatek;
	} 
}

int** tworz_tabela(int rozmiar)
{
	srand((unsigned int) time(NULL));
	int **p = (int **) malloc (rozmiar * sizeof(int *));
    p[0]=(int*)malloc(rozmiar * rozmiar *sizeof(int));
    int i=1;
    for(; i < rozmiar; i++)
    {
        p[i] = p[0]+ i * rozmiar;
    }
    int a=0;
	for( ;a<rozmiar ;a++){
		int b=0 ;
		for(;b<rozmiar ;b++) 
			p[a][b]=(rand()%2? martwa: zywa);
	}
		
	return p;
}

void **realia_zyciowe(int **tabela,int rozmiar)
{
	int x,y;
	int sasiedzi=0;
		x=0; y=0;
		if(tabela[x][y]==zywa) 		sasiedzi++;
		if(tabela[x+1][y]==zywa) 	sasiedzi++;
		if(tabela[x+1][y+1]==zywa) 	sasiedzi++;
		if(tabela[x][y+1]==zywa) 	sasiedzi++;
		reakcja_na_stan(tabela,x,y,sasiedzi);
		sasiedzi=0;
	
		x=0; y=rozmiar-1;
		if(tabela[x][y]==zywa) 		sasiedzi++;
		if(tabela[x][y-1]==zywa) 	sasiedzi++;
		if(tabela[x+1][y-1]==zywa) 	sasiedzi++;
		if(tabela[x+1][y]==zywa) 	sasiedzi++;
		reakcja_na_stan(tabela,x,y,sasiedzi);
		sasiedzi=0;
	
		x=rozmiar-1; y=0;
		if(tabela[x][y]==zywa) 		sasiedzi++;
		if(tabela[x][y+1]==zywa) 	sasiedzi++;
		if(tabela[x-1][y+1]==zywa) 	sasiedzi++;
		if(tabela[x-1][y]==zywa) 	sasiedzi++;
		reakcja_na_stan(tabela,x,y,sasiedzi);
		sasiedzi=0;
		
		x=rozmiar-1; y=rozmiar-1;
		if(tabela[x-1][y-1]==zywa) 	sasiedzi++;
		if(tabela[x-1][y]==zywa) 	sasiedzi++;
		if(tabela[x][y]==zywa) 		sasiedzi++;
		if(tabela[x][y-1]==zywa) 	sasiedzi++;
		reakcja_na_stan(tabela,x,y,sasiedzi);
		sasiedzi=0;
		
		x=0;
		int z=1;
		for(;z<rozmiar-1;z++){
			if(tabela[x][z-1]==zywa) 	sasiedzi++;
			if(tabela[x+1][z-1]==zywa) 	sasiedzi++;
			if(tabela[x+1][z]==zywa) 		sasiedzi++;
			if(tabela[x+1][z+1]==zywa) 	sasiedzi++;
			if(tabela[x][z+1]==zywa) 	sasiedzi++;
			reakcja_na_stan(tabela,x,z,sasiedzi);
			sasiedzi=0;
		}
		x=rozmiar-1;
		z=1;
		for(;z<rozmiar-1;z++){
			if(tabela[x][z-1]==zywa) 		sasiedzi++;
			if(tabela[x-1][z-1]==zywa) 	sasiedzi++;
			if(tabela[x-1][z]==zywa) 		sasiedzi++;
			if(tabela[x-1][z+1]==zywa) 	sasiedzi++;
			if(tabela[x][z+1]==zywa) 		sasiedzi++;
			reakcja_na_stan(tabela,x,z,sasiedzi);
			sasiedzi=0;
		}
		
		x=0;
		z=1;
		for(;z<rozmiar-1;z++){
			if(tabela[z-1][x]==zywa) 	sasiedzi++;
			if(tabela[z-1][x+1]==zywa) 	sasiedzi++;
			if(tabela[z][x+1]==zywa) 		sasiedzi++;
			if(tabela[z+1][x+1]==zywa) 	sasiedzi++;
			if(tabela[z+1][x]==zywa) 	sasiedzi++;
			reakcja_na_stan(tabela,z,x,sasiedzi);
			sasiedzi=0;
		}
		
		x=rozmiar-1;
		z=1;
		for(;z<rozmiar-1;z++){
			if(tabela[z-1][x]==zywa) 		sasiedzi++;
			if(tabela[z-1][x-1]==zywa) 	sasiedzi++;
			if(tabela[z][x-1]==zywa) 		sasiedzi++;
			if(tabela[z+1][x-1]==zywa) 	sasiedzi++;
			if(tabela[z+1][x]==zywa) 		sasiedzi++;
			reakcja_na_stan(tabela,z,x,sasiedzi);
			sasiedzi=0;
		}

			for(x=1;x<rozmiar-1;x++)
			{
				for(y=1;y<rozmiar-1;y++)
				{
		if(tabela[x][y]==zywa) 		sasiedzi++;
		if(tabela[x-1][y]==zywa) 	sasiedzi++;
		if(tabela[x-1][y+1]==zywa) 	sasiedzi++;
		if(tabela[x][y+1]==zywa) 	sasiedzi++;
		if(tabela[x+1][y+1]==zywa) 	sasiedzi++;
		if(tabela[x+1][y]==zywa) 	sasiedzi++;
		if(tabela[x+1][y-1]==zywa) 	sasiedzi++;
		if(tabela[x][y-1]==zywa) 	sasiedzi++;
		if(tabela[x-1][y-1]==zywa) 	sasiedzi++;
		reakcja_na_stan(tabela,x,y,sasiedzi);
		sasiedzi=0;
				}
			}	
}

void reakcja_na_stan(int **tabela,int x,int y,int sasiedzi)
{
	if(sasiedzi==3 && tabela[x][y] == martwa)  
	{
		tabela[x][y]=zywa;
	}
	if(sasiedzi==3 || sasiedzi==2 && tabela[x][y] == zywa) /*stan normalny*/
	{
		tabela[x][y]=zywa;
	}
	if(sasiedzi<2 || sasiedzi>=4) /*smierc w tloku lub z samotnosci*/
	{
		tabela[x][y]=martwa;
	}
}

void pokaz_tablice(int **tabela, int rozmiar)
{
	int x=0;
	for(;x<rozmiar;x++)
	{
		int y=0;
		for(;y<rozmiar;y++)
		{
			printf("%c",tabela[x][y]);
		}
		printf("\n");
	}
}
