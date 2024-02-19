#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <string.h>

#include <windows.h>
#include <mmsystem.h>

#define MAX 20

using namespace std;
int screenHeight=GetSystemMetrics(SM_CYSCREEN);
int screenWidth=GetSystemMetrics(SM_CXSCREEN);
int margineX,margineY,width,height,latura;
bool gata;
int lin,col,lvl;
int numar;
int TablaDeJoc[MAX][MAX];
int n;
bool Gabi1=false;
int piesaAleasa;
int lv, cv, la, ca, ln, cn;
int cnt =0;

bool LANGUAGE;
//LANGUAGE=0 romana
//LANGUAGE=1 engleza

bool blocat=false;
bool language=1;

int ln1,cn1,la1,ca1,lv1,cv1;

struct punct
{
    int x, y;
};
struct dreptunghi
{
    punct SS, DJ;
};
bool apartine(punct P, dreptunghi D)
{
    return D.SS.x<=P.x && P.x<=D.DJ.x && D.SS.y<=P.y && P.y<=D.DJ.y;
}
struct buton
{
    dreptunghi D;
    int culoare;
    char text[20];
};

buton B[6];//butoane meniu
buton N[6];//butoane nivel
buton S[9];//setari
int nrButoane=5;
int nrNivele=5;
int nrSetari=8;
int model_tabla;

void beginning(void)
{
    delay(100);
    //chenare colorate
    setcolor(LIGHTBLUE);
    int x=getmaxx();//maximul coord x a ferestrei
    for(int i=0; i<=190; i++)
        setcolor(i%4),rectangle(i,i,screenWidth-i,screenHeight-i),delay(3);
    delay(200);

    //text
    setcolor(WHITE);
    settextstyle(BOLD_FONT,HORIZ_DIR,8);
    outtextxy(590,370,"WELCOME!");
    delay(200);
    settextstyle(BOLD_FONT,HORIZ_DIR,4);
    outtextxy(555,590,"Press any key to start");

    getch();
    delay(20);
    cleardevice();
}

void Mutare(int x)
{
    if(x%2==0)
    {
        if(language==0)
            readimagefile("jucator2.jpg",screenWidth-533,450,screenWidth,screenHeight);
        else
            readimagefile("player2.jpg",screenWidth-533,450,screenWidth,screenHeight);
    }
    else
    {
        if(language==0)
            readimagefile("jucator1.jpg",screenWidth-533,450,screenWidth,screenHeight);
        else
            readimagefile("player1.jpg",screenWidth-533,450,screenWidth,screenHeight);
    }
}

int contur_piesa_urmatoare(int lin,int col)
{

    int stanga=margineX;
    int sus=margineY;
    int x1=margineX+latura*(col-1);
    int y1=sus+latura*(lin-1);
    int x2=x1+latura;
    int y2=y1+latura;
    setcolor(RED);

    if(lvl==1)
    {
        line(x1+4,y1+4,x2-4,y2-4);
        line(x1+4,y1+14,x2-14,y2-4);
        line(x1+4,y1+24,x2-24,y2-4);
        line(x1+4,y1+34,x2-34,y2-4);
        line(x1+4,y1+44,x2-44,y2-4);
        line(x1+4,y1+54,x2-54,y2-4);
        line(x1+4,y1+64,x2-64,y2-4);
        line(x1+4,y1+74,x2-74,y2-4);
        line(x1+4,y1+84,x2-84,y2-4);
        line(x1+4,y1+94,x2-94,y2-4);
        line(x1+4,y1+104,x2-104,y2-4);
        line(x1+4,y1+114,x2-114,y2-4);
        line(x1+4,y1+124,x2-124,y2-4);
        line(x1+4,y1+134,x2-134,y2-4);
        line(x1+4,y1+144,x2-144,y2-4);
        line(x1+4,y1+154,x2-154,y2-4);
        line(x1+4,y1+164,x2-164,y2-4);
        line(x1+4,y1+174,x2-174,y2-4);


        line(x1+14,y1+4,x2-4,y2-14);
        line(x1+24,y1+4,x2-4,y2-24);
        line(x1+34,y1+4,x2-4,y2-34);
        line(x1+44,y1+4,x2-4,y2-44);
        line(x1+54,y1+4,x2-4,y2-54);
        line(x1+64,y1+4,x2-4,y2-64);
        line(x1+74,y1+4,x2-4,y2-74);
        line(x1+84,y1+4,x2-4,y2-84);
        line(x1+94,y1+4,x2-4,y2-94);
        line(x1+104,y1+4,x2-4,y2-104);
        line(x1+114,y1+4,x2-4,y2-114);
        line(x1+124,y1+4,x2-4,y2-124);
        line(x1+134,y1+4,x2-4,y2-134);
        line(x1+144,y1+4,x2-4,y2-144);
        line(x1+154,y1+4,x2-4,y2-154);
        line(x1+164,y1+4,x2-4,y2-164);
        line(x1+174,y1+4,x2-4,y2-174);
    }

    if(lvl ==2 )
    {
        line(x1+4,y1+4,x2-4,y2-4);
        line(x1+4,y1+14,x2-14,y2-4);
        line(x1+4,y1+24,x2-24,y2-4);
        line(x1+4,y1+34,x2-34,y2-4);
        line(x1+4,y1+44,x2-44,y2-4);
        line(x1+4,y1+54,x2-54,y2-4);
        line(x1+4,y1+64,x2-64,y2-4);
        line(x1+4,y1+74,x2-74,y2-4);
        line(x1+4,y1+84,x2-84,y2-4);
        line(x1+4,y1+94,x2-94,y2-4);
        line(x1+4,y1+104,x2-104,y2-4);
        line(x1+4,y1+114,x2-114,y2-4);
        line(x1+4,y1+124,x2-124,y2-4);
        line(x1+4,y1+134,x2-134,y2-4);
        line(x1+4,y1+144,x2-144,y2-4);


        line(x1+14,y1+4,x2-4,y2-14);
        line(x1+24,y1+4,x2-4,y2-24);
        line(x1+34,y1+4,x2-4,y2-34);
        line(x1+44,y1+4,x2-4,y2-44);
        line(x1+54,y1+4,x2-4,y2-54);
        line(x1+64,y1+4,x2-4,y2-64);
        line(x1+74,y1+4,x2-4,y2-74);
        line(x1+84,y1+4,x2-4,y2-84);
        line(x1+94,y1+4,x2-4,y2-94);
        line(x1+104,y1+4,x2-4,y2-104);
        line(x1+114,y1+4,x2-4,y2-114);
        line(x1+124,y1+4,x2-4,y2-124);
        line(x1+134,y1+4,x2-4,y2-134);
        line(x1+144,y1+4,x2-4,y2-144);
    }

    if(lvl==3)
    {

        line(x1+4,y1+4,x2-4,y2-4);
        line(x1+4,y1+14,x2-14,y2-4);
        line(x1+4,y1+24,x2-24,y2-4);
        line(x1+4,y1+34,x2-34,y2-4);
        line(x1+4,y1+44,x2-44,y2-4);
        line(x1+4,y1+54,x2-54,y2-4);
        line(x1+4,y1+64,x2-64,y2-4);
        line(x1+4,y1+74,x2-74,y2-4);
        line(x1+4,y1+84,x2-84,y2-4);
        line(x1+4,y1+94,x2-94,y2-4);
        line(x1+4,y1+104,x2-104,y2-4);
        line(x1+4,y1+114,x2-114,y2-4);


        line(x1+14,y1+4,x2-4,y2-14);
        line(x1+24,y1+4,x2-4,y2-24);
        line(x1+34,y1+4,x2-4,y2-34);
        line(x1+44,y1+4,x2-4,y2-44);
        line(x1+54,y1+4,x2-4,y2-54);
        line(x1+64,y1+4,x2-4,y2-64);
        line(x1+74,y1+4,x2-4,y2-74);
        line(x1+84,y1+4,x2-4,y2-84);
        line(x1+94,y1+4,x2-4,y2-94);
        line(x1+104,y1+4,x2-4,y2-104);
        line(x1+114,y1+4,x2-4,y2-114);
    }

    if(lvl == 4)
    {
        line(x1+4,y1+4,x2-4,y2-4);
        line(x1+4,y1+14,x2-14,y2-4);
        line(x1+4,y1+24,x2-24,y2-4);
        line(x1+4,y1+34,x2-34,y2-4);
        line(x1+4,y1+44,x2-44,y2-4);
        line(x1+4,y1+54,x2-54,y2-4);
        line(x1+4,y1+64,x2-64,y2-4);
        line(x1+4,y1+74,x2-74,y2-4);
        line(x1+4,y1+84,x2-84,y2-4);
        line(x1+4,y1+94,x2-94,y2-4);
        line(x1+4,y1+104,x2-104,y2-4);


        line(x1+14,y1+4,x2-4,y2-14);
        line(x1+24,y1+4,x2-4,y2-24);
        line(x1+34,y1+4,x2-4,y2-34);
        line(x1+44,y1+4,x2-4,y2-44);
        line(x1+54,y1+4,x2-4,y2-54);
        line(x1+64,y1+4,x2-4,y2-64);
        line(x1+74,y1+4,x2-4,y2-74);
        line(x1+84,y1+4,x2-4,y2-84);
        line(x1+94,y1+4,x2-4,y2-94);
        line(x1+104,y1+4,x2-4,y2-104);

    }


    if(lvl==5)
    {
        line(x1+4,y1+4,x2-4,y2-4);
        line(x1+4,y1+14,x2-14,y2-4);
        line(x1+4,y1+24,x2-24,y2-4);
        line(x1+4,y1+34,x2-34,y2-4);
        line(x1+4,y1+44,x2-44,y2-4);
        line(x1+4,y1+54,x2-54,y2-4);
        line(x1+4,y1+64,x2-64,y2-4);
        line(x1+4,y1+74,x2-74,y2-4);
        line(x1+4,y1+84,x2-84,y2-4);



        line(x1+14,y1+4,x2-4,y2-14);
        line(x1+24,y1+4,x2-4,y2-24);
        line(x1+34,y1+4,x2-4,y2-34);
        line(x1+44,y1+4,x2-4,y2-44);
        line(x1+54,y1+4,x2-4,y2-54);
        line(x1+64,y1+4,x2-4,y2-64);
        line(x1+74,y1+4,x2-4,y2-74);
        line(x1+84,y1+4,x2-4,y2-84);
    }
    return 0;
}

void contur_piesa_aleasa(int x)
{
    if(Gabi1==false)
    {
        setcolor(RED);
        if(x==1)
        {
            rectangle(1021,91,1159,229);
            rectangle(1022,92,1158,228);
            rectangle(1023,93,1157,227);
            rectangle(1024,94,1156,226);
            rectangle(1025,95,1155,225);
            rectangle(1026,96,1154,224);
            rectangle(1027,97,1153,223);
            rectangle(1028,98,1152,222);
        }
        if(x==2)
        {
            rectangle(1191,91,1329,229);
            rectangle(1192,92,1328,228);
            rectangle(1193,93,1327,227);
            rectangle(1194,94,1326,226);
            rectangle(1195,95,1325,225);
            rectangle(1196,96,1324,224);
            rectangle(1197,97,1323,223);
            rectangle(1198,98,1322,222);
        }
        if(x==3)
        {
            rectangle(1361,91,1499,229);
            rectangle(1362,92,1498,228);
            rectangle(1363,93,1497,227);
            rectangle(1364,94,1496,226);
            rectangle(1365,95,1495,225);
            rectangle(1366,96,1494,224);
            rectangle(1367,97,1493,223);
            rectangle(1368,98,1492,222);
        }
    }
    else
    {
        setcolor(BLACK);
        if(x==1)
        {
            rectangle(1021,91,1159,229);
            rectangle(1022,92,1158,228);
            rectangle(1023,93,1157,227);
            rectangle(1024,94,1156,226);
            rectangle(1025,95,1155,225);
            rectangle(1026,96,1154,224);
            rectangle(1027,97,1153,223);
            setcolor(MAGENTA);
            rectangle(1028,98,1152,222);
        }
        if(x==2)
        {
            rectangle(1191,91,1329,229);
            rectangle(1192,92,1328,228);
            rectangle(1193,93,1327,227);
            rectangle(1194,94,1326,226);
            rectangle(1195,95,1325,225);
            rectangle(1196,96,1324,224);
            rectangle(1197,97,1323,223);
            setcolor(MAGENTA);
            rectangle(1198,98,1322,222);
        }
        if(x==3)
        {
            rectangle(1361,91,1499,229);
            rectangle(1362,92,1498,228);
            rectangle(1363,93,1497,227);
            rectangle(1364,94,1496,226);
            rectangle(1365,95,1495,225);
            rectangle(1366,96,1494,224);
            rectangle(1367,97,1493,223);
            setcolor(MAGENTA);
            rectangle(1368,98,1492,222);
        }
    }
    setcolor(MAGENTA);
}

void Loading_Game(void)
{
    //poze piese loading + contur
    bar(190,190,410,410);
    readimagefile("piesa_colt1.jpg",200,200,400,400);

    bar(640,190,860,410);
    readimagefile("piesa_cruce.jpg",650,200,850,400);

    bar(1090,190,1310,410);
    readimagefile("piesa_colt2.jpg",1100,200,1300,400);

    //loading text+chenar
    rectangle(400,620,1110,680);
    rectangle(399,621,1109,681);
    rectangle(398,622,1108,682);

    setcolor(WHITE);
    settextstyle(BOLD_FONT,HORIZ_DIR,4);
    outtextxy(675,700,"LOADING...");

    setcolor(BLUE);
    for(int i=0; i<=712; i++)
    {
        line(398+i,620,398+i,682);
        delay(1);
    }
    delay(100);
    cleardevice();
}

void prezentare_piese(void)
{
    setcolor(MAGENTA);
    int i;
    for(i=0; i<=7; i++)
        rectangle(1002+i,0+i,screenWidth-3.5-i,450-i);
    settextstyle(BOLD_FONT,HORIZ_DIR,3);
    if (language==1)
        outtextxy(1025,20,"The pieces you are allowed to use:");
    else
        outtextxy(1025,20,"Piesele care pot fi folosite sunt:");

    //contur pt fiecare imagine => x mai mic & y mai mare(ingrosam in afara imaginii)
    readimagefile("piesa_cruce.jpg",1030,100,1150,220);
    rectangle(1029,99,1151,221);
    rectangle(1028,98,1152,222);

    readimagefile("piesa_colt2.jpg",1200,100,1320,220);
    rectangle(1199,99,1321,221);
    rectangle(1198,98,1322,222);

    readimagefile("piesa_colt1.jpg",1370,100,1490,220);
    rectangle(1369,99,1491,221);
    rectangle(1368,98,1492,222);

    if(language==1)
        readimagefile("attention.jpg",1010,230,screenWidth-15,445);
    else
        readimagefile("atentie.jpg",1010,230,screenWidth-15,445);

    if(language==0)
        readimagefile("jucator1.jpg",screenWidth-533,450,screenWidth,screenHeight);
    else
        readimagefile("player1.jpg",screenWidth-533,450,screenWidth,screenHeight);
}

void initTabla()
{
    n=numar;
    int i,j;
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
            TablaDeJoc[i][j]=0;
    TablaDeJoc[1][1]=1; // +
    TablaDeJoc[1][0]=1; // +
    la=1;
    ca=1;
    lv=1;
    cv=0;
}

void matriceTabla(void)
{
    int i,j;
    width=850;
    height=850;
    margineX=50;
    margineY=50;
    setfillstyle(SOLID_FILL,DARKGRAY);
    switch(model_tabla)
    {
    case 1:
        setfillstyle(SOLID_FILL,LIGHTGRAY);
        setcolor(LIGHTBLUE);
        break;
    case 2:
        setfillstyle(SOLID_FILL,LIGHTMAGENTA);
        setcolor(MAGENTA);
        break;
    case 3:
        setfillstyle(SOLID_FILL,CYAN);
        setcolor(LIGHTCYAN);
        break;
    case 4:
        setfillstyle(SOLID_FILL,DARKGRAY);
        setcolor(LIGHTGREEN);
        break;
    }
    if(numar==8)
       bar(margineX,margineY,795,795);
    else
        bar(margineX,margineY,800,800);
    latura=(height-2*margineY)/numar;
    for(i=1; i<=numar; i++)
    {
        for(j=1; j<=numar; j++)
        {
            rectangle(margineX+latura*(i-1),margineY+latura*(j-1),margineX+latura*i,margineY+latura*j);
            //contur pt fiecare patrat => x mai mare si y mai mic
            rectangle(margineX+latura*(i-1)+1,margineY+latura*(j-1)-1,margineX+latura*i+1,margineY+latura*j-1);
            rectangle(margineX+latura*(i-1)+2,margineY+latura*(j-1)-2,margineX+latura*i+2,margineY+latura*j-2);
        }
    }
    //linie separatoare
    setcolor(LIGHTCYAN);
    line(999,0,999,screenHeight);
    line(1000,0,1000,screenHeight);
    line(1001,0,1001,screenHeight);

    //inserare piese cruce + colt negru
    int stanga=margineX;
    int sus=margineY;
    int linia=1,coloana=1;
    int x1=margineX+latura*(coloana-1);
    int y1=sus+latura*(linia-1);
    int x2=x1+latura;
    int y2=y1+latura;
    bar(x1+3,y1+1,x2-1,y2-2);
    //aici punem piesa inititala (cruce)
    readimagefile("piesa_cruce.jpg",x1+3,y1+1,x2-1,y2-3);
    //aici punem coltul negru
    setfillstyle(SOLID_FILL,BLACK);
    i=numar,j=numar;//numar=nr de patratele
    bar(margineX+latura*(i-1)+3,margineY+latura*(j-1)+1,margineX+latura*i-1,margineY+latura*j-3);
}

void deseneazaMeniul()
{
    if(language==1)
        readimagefile("background_en.jpg",0,0,screenWidth,screenHeight);
    else
        readimagefile("background_ro.jpg",0,0,screenWidth,screenHeight);
    setfillstyle(SOLID_FILL,LIGHTCYAN);
    int i;
    for (i=1; i<=nrButoane; i++)
    {
        //stanga sus
        B[i].D.SS.x=screenWidth/2-170;//cat la stanga de mijloc incepe
        B[i].D.SS.y=screenHeight/2-125+i*85;//spatiul intre butoane
        //dreapta jos
        B[i].D.DJ.x=screenWidth/2+170;//cat la dreapta se duce(200 ca sa cuprinda tot cuvantul instructiune)
        B[i].D.DJ.y=B[i].D.SS.y+70;
        settextstyle(BOLD_FONT,HORIZ_DIR,5);
        setcolor(MAGENTA);
        switch(i)
        {
        case 1:
            if(language==0)
                strcpy(B[i].text,"  START  JOC  ");
            else
                strcpy(B[i].text,"  START GAME  ");
            break;
        case 2:
            if(language==0)
                strcpy(B[i].text," INSTRUCTIUNI ");
            else
                strcpy(B[i].text," INSTRUCTIONS ");
            break;
        case 3:
            if(language==0)
                strcpy(B[i].text,"   CREATORI   ");
            else
                strcpy(B[i].text,"   CREATORS   ");
            break;
        case 4:
            if(language==0)
                strcpy(B[i].text,"    SETARI    ");
            else
                strcpy(B[i].text,"   SETTINGS   ");
            break;
        case 5:
            if(language==0)
                strcpy(B[i].text,"    IESIRE    ");
            else
                strcpy(B[i].text,"     EXIT     ");
            break;
        }
        outtextxy(B[i].D.SS.x,B[i].D.SS.y+25,B[i].text);
        //setcolor(YELLOW);
        //line(B[i].D.SS.x,B[i].D.SS.y,B[i].D.DJ.x,B[i].D.DJ.y);
    }
}

void minimatrice(int n, int ssx, int ssy, int djx, int djy)
{
    int i,j;
    width=djx-ssx;
    height=djy-ssy;
    margineX=ssx+250;
    margineY=ssy+50;
    setcolor(LIGHTBLUE);
    latura=(height-100)/n;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            rectangle(margineX+latura*(i-1),margineY+latura*(j-1),margineX+latura*i,margineY+latura*j);
}

void desenNivel()
{
    //readimagefile("4.jpg",0,0,screenWidth,screenHeight);
    setfillstyle(SOLID_FILL,BLUE);
    bar(0,0,screenWidth,10);
    bar(0,0,10,screenHeight);
    bar(screenWidth-10,0,screenWidth,screenHeight);
    bar(0,screenHeight-10,screenWidth,screenHeight);
    setcolor(CYAN);
    if(language==1)
        outtextxy(screenWidth/2-200,30,"SELECT GAME LEVEL");
    else
        outtextxy(screenWidth/2-200,30,"SELECTEAZA NIVELUL");
    int i;
    for (i=1; i<=3; i++)
    {
        //stanga sus
        N[i].D.SS.x=-425+i*500;
        N[i].D.SS.y=200;
        //dreapta jos
        N[i].D.DJ.x=N[i].D.SS.x+400;
        N[i].D.DJ.y=N[i].D.SS.y+200;
        settextstyle(BOLD_FONT,HORIZ_DIR,4);
        switch(i)
        {
        case 1:
            if(language==1)
                strcpy(N[i].text,"LEVEL I");
            else
                strcpy(N[i].text,"NIVEL 1");
            minimatrice(4,N[i].D.SS.x,N[i].D.SS.y,N[i].D.DJ.x,N[i].D.DJ.y);
            break;
        case 2:
            if(language==1)
                strcpy(N[i].text,"LEVEL II");
            else
                strcpy(N[i].text,"NIVEL 2");
            minimatrice(5,N[i].D.SS.x,N[i].D.SS.y,N[i].D.DJ.x,N[i].D.DJ.y);
            break;
        case 3:
            if(language==1)
                strcpy(N[i].text,"LEVEL III");
            else
                strcpy(N[i].text,"NIVEL 3");
            minimatrice(6,N[i].D.SS.x,N[i].D.SS.y,N[i].D.DJ.x,N[i].D.DJ.y);
            break;
        }
        setcolor(CYAN);
        outtextxy(N[i].D.SS.x+15,N[i].D.SS.y+85,N[i].text);
        //setcolor(YELLOW);
        //line(N[i].C.ss.x,N[i].C.ss.y,N[i].C.dj.x,N[i].C.dj.y);
        setcolor(BLUE);
        rectangle(N[i].D.SS.x,N[i].D.SS.y,N[i].D.DJ.x,N[i].D.DJ.y);
        rectangle(N[i].D.SS.x+1,N[i].D.SS.y+1,N[i].D.DJ.x-1,N[i].D.DJ.y-1);
    }
    int k=1;
    for(i=4; i<=5; i++)
    {
        //stanga sus
        N[i].D.SS.x=-175+k*500;
        N[i].D.SS.y=500;
        k++;
        //dreapta jos
        N[i].D.DJ.x=N[i].D.SS.x+400;
        N[i].D.DJ.y=N[i].D.SS.y+200;
        settextstyle(BOLD_FONT,HORIZ_DIR,4);
        switch(i)
        {
        case 4:
            if(language==1)
                strcpy(N[i].text,"LEVEL IV");
            else
                strcpy(N[i].text,"NIVEL 4");
            minimatrice(7,N[i].D.SS.x,N[i].D.SS.y,N[i].D.DJ.x,N[i].D.DJ.y);
            break;
        case 5:
            if(language==1)
                strcpy(N[i].text,"LEVEL V");
            else
                strcpy(N[i].text,"NIVEL 5");
            minimatrice(8,N[i].D.SS.x,N[i].D.SS.y,N[i].D.DJ.x,N[i].D.DJ.y);
            break;
        }
        setcolor(CYAN);
        outtextxy(N[i].D.SS.x+15,N[i].D.SS.y+85,N[i].text);
        //setcolor(YELLOW);
        //line(N[i].C.ss.x,N[i].C.ss.y,N[i].C.dj.x,N[i].C.dj.y);
        setcolor(BLUE);
        rectangle(N[i].D.SS.x,N[i].D.SS.y,N[i].D.DJ.x,N[i].D.DJ.y);
        rectangle(N[i].D.SS.x+1,N[i].D.SS.y+1,N[i].D.DJ.x-1,N[i].D.DJ.y-1);
    }
    //readimagefile("settings.jpg",0,0,screenWidth,screenHeight);
    setfillstyle(SOLID_FILL,BLACK);
    setcolor(LIGHTCYAN);
    bar(10,10,135,50);
    rectangle(10,10,135,50);
    settextstyle(BOLD_FONT,HORIZ_DIR,4);
    if(language==1)
        outtextxy(15,15," BACK");
    else
        outtextxy(15,15,"INAPOI");
}


int butonAles()
{
    int i;
    punct p;
    if (ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        p.x=mousex();
        p.y=mousey();
        for (i=1; i<=nrButoane; i++)
            if (apartine(p,B[i].D))
                return i;
    }
    return 0;
}

void MENIU();

int NivelAles()
{
    int i;
    punct pp;
    if (ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        pp.x=mousex();
        pp.y=mousey();
        for (i=1; i<=nrNivele; i++)
            if (apartine(pp,N[i].D))
            {
                lvl=i;
                return i;
            }
            else if(pp.x>=10 && pp.x<=140 && pp.y>=10 && pp.y<=50)
                MENIU();
    }
    return 0;
}

void alegePiesa(int &p)
{
    int x,y;
    p=0;
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();
        if (x>=1030 && x<=1150 && y>=100 && y<=220)
        {
            Gabi1=false;
            p=1;
            contur_piesa_aleasa(p);
        }
        if (x>=1200 && x<=1320 && y>=100 && y<=220)
        {
            Gabi1=false;
            p=2;
            contur_piesa_aleasa(p);

        }
        if (x>=1370 && x<=1490 && y>=100 && y<=220)
        {
            Gabi1=false;
            p=3;
            contur_piesa_aleasa(p);

        }
    }
}




bool vinDinStanga1()
{
    return lv1==la1&& cv1==ca1-1;
}

bool vinDeSus1()
{
    return lv1==la1-1 && cv1==ca1;
}

bool vinDinDreapta1()
{
    return lv1==la1 && cv1==ca1+1;
}

bool vinDeJos1()
{
    return lv1==la1+1 && cv1==ca1;
}

void mergJos1()
{
    cn1=ca1;
    ln1=la1+1;
}

void mergSus1()
{
    cn1=ca1;
    ln1=la1-1;
}

void mergStanga1()
{
    cn1=ca1-1;
    ln1=la1;
}

void mergDreapta1()
{
    cn1=ca1+1;
    ln1=la1;
}





bool vinDinStanga()
{
    return lv==la && cv==ca-1;
}

bool vinDeSus()
{
    return lv==la-1 && cv==ca;
}

bool vinDinDreapta()
{
    return lv==la && cv==ca+1;
}

bool vinDeJos()
{
    return lv==la+1 && cv==ca;
}

void mergJos()
{
    cn=ca;
    ln=la+1;
}

void mergSus()
{
    cn=ca;
    ln=la-1;
}

void mergStanga()
{
    cn=ca-1;
    ln=la;
}

void mergDreapta()
{
    cn=ca+1;
    ln=la;
}




void calculeazaLoculUndeTrebuiePusaPiesa()
{
    do
    {
        switch(TablaDeJoc[la][ca])
        {
        /* piesa 1 = + */
        case 1:
            if (vinDinStanga()) mergDreapta();
            else if (vinDinDreapta()) mergStanga();
            else if (vinDeJos()) mergSus();
            else mergJos();
            break;
        /* piesa 2 = // */
        case 2:
            if (vinDinStanga()) mergSus();
            else if (vinDinDreapta()) mergJos();
            else if (vinDeJos()) mergDreapta();
            else mergStanga();
            break;
        /* piesa 3 = \\ */
        case 3:
            if (vinDinStanga()) mergJos();
            else if (vinDinDreapta()) mergSus();
            else if (vinDeJos()) mergStanga();
            else mergDreapta();
            break;
        }
        //cout<<"     lv="<<lv<<" cv="<<cv<<", la="<<la<<" ca="<<ca<<" -> ln="<<ln<<" cn="<<cn<<endl;
        lv=la;
        cv=ca;
        la=ln;
        ca=cn;
    }
    while (TablaDeJoc[ln][cn]!=0);
    cout<<ln<<" "<<cn<<" "<<"f0"<<endl;
}

void calculeazaLoculUndeTrebuiePusaPiesa1()
{
    lv1=lv;
    cv1=cv;
    la1=ln;
    ca1=cn;
    do
    {
        switch(TablaDeJoc[la1][ca1])
        {
        /* piesa 1 = + */
        case 1:
            if (vinDinStanga1()) mergDreapta1();
            else if (vinDinDreapta1()) mergStanga1();
            else if (vinDeJos1()) mergSus1();
            else mergJos1();
            break;

        /* piesa 2 = // */
        case 2:
            if (vinDinStanga1()) mergSus1();
            else if (vinDinDreapta1()) mergJos1();
            else if (vinDeJos1()) mergDreapta1();
            else mergStanga1();
            break;
        /* piesa 3 = \\ */
        case 3:
            if (vinDinStanga1()) mergJos1();
            else if (vinDinDreapta1()) mergSus1();
            else if (vinDeJos1()) mergStanga1();
            else mergDreapta1();
            break;

        }
        //cout<<"     lv="<<lv<<" cv="<<cv<<", la="<<la<<" ca="<<ca<<" -> ln="<<ln<<" cn="<<cn<<endl;
        lv1=la1;
        cv1=ca1;
        la1=ln1;
        ca1=cn1;
    }
    while (TablaDeJoc[ln1][cn1]!=0);


    cout<<ln1<<" "<<cn1<<" "<<"f1"<<endl;
}

bool punerePiesa()
{
    int stanga=margineX;
    int sus=margineY;
    int linia,coloana,x,y;
    int x1, y1, x2, y2;
    bool ok=false;
    bool alegere_corecta;
    int lv1=lv, cv1=cv, la1=la, ca1=ca;
    setbkcolor(BLACK);
    setcolor(MAGENTA);
    settextstyle(SOLID_FILL,HORIZ_DIR,5);
    x1=margineX+latura*(coloana-1);
    y1=sus+latura*(linia-1);
    x2=x1+latura;
    y2=y1+latura;
    bar(x1+3,y1+1,x2-1,y2-2);
    do
    {
        alegere_corecta=false;
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
            if(!blocat)//daca nu este selectata nicio piesa
            {
                if (x>=margineX && x<=width-stanga && y>=sus&&y<=height-sus)//verif daca click apartine matricei
                {
                    //calculeaza in ce patrat s-a facut click
                    linia=(y-sus)/latura+1;
                    coloana=(x-stanga)/latura+1;

                    calculeazaLoculUndeTrebuiePusaPiesa(); // determina ln,cn pt a vedea unde trebuie pusa piesa
                    alegere_corecta=TablaDeJoc[linia][coloana]==0 && linia==ln && coloana==cn;
                    // cout<<"lv="<<lv<<" cv="<<cv<<", la="<<la<<" ca="<<ca<<" -> ln="<<ln<<" cn="<<cn<<endl;
                    if (alegere_corecta)
                    {
                        Beep(1500,200);
                        TablaDeJoc[linia][coloana]=piesaAleasa;
                        calculeazaLoculUndeTrebuiePusaPiesa1();



                        if(ln1==0 || cn1 == 0|| ln1 == numar +1 || cn1 == numar+1)
                            outtextxy(screenWidth-480,screenHeight-300,"AI PIERDUT!");

                        char numeFisier[10];
                        switch (piesaAleasa)
                        {
                        case 1:
                            strcpy(numeFisier,"piesa_cruce.jpg");
                            break;
                        case 2:
                            strcpy(numeFisier,"piesa_colt2.jpg");
                            break;
                        case 3:
                            strcpy(numeFisier,"piesa_colt1.jpg");
                            break;
                        }
                        setfillstyle(SOLID_FILL,LIGHTGRAY);
                        x1=margineX+latura*(coloana-1);
                        y1=sus+latura*(linia-1);
                        x2=x1+latura;
                        y2=y1+latura;
                        bar(x1+3,y1+1,x2-1,y2-2);
                        readimagefile(numeFisier,x1+3,y1+1,x2-1,y2-3);
                        Mutare(cnt);

                        cnt++;

                        Gabi1=true;
                        contur_piesa_aleasa(piesaAleasa);

                        bool Gabi =0;
                        settextstyle(SOLID_FILL,HORIZ_DIR,5);

                        if(TablaDeJoc[numar-1][numar]==1 || TablaDeJoc[numar][numar-1]==1)
                        {
                            if(language==1)
                            {
                                settextstyle(BOLD_FONT,HORIZ_DIR,5);
                                readimagefile("winner.jpg",screenWidth-533,450,screenWidth,screenHeight);
                                if(cnt%2==1)
                                        outtextxy(screenWidth-400,470," Player 1");
                                else
                                    outtextxy(screenWidth-400,470," Player 2");
                            }
                            else
                            {
                                settextstyle(BOLD_FONT,HORIZ_DIR,5);
                                readimagefile("castigator.jpg",screenWidth-533,450,screenWidth,screenHeight);
                                if(cnt%2==1)
                                    outtextxy(screenWidth-400,470,"Jucator 1");
                                else
                                    outtextxy(screenWidth-400,470,"Jucator 2");
                            }
                            blocat=true;
                        }
                        if(TablaDeJoc[numar-1][numar]==3 || TablaDeJoc[numar][numar-1]==3)
                        {
                            if(language==1)
                            {
                                settextstyle(BOLD_FONT,HORIZ_DIR,5);
                                readimagefile("winner.jpg",screenWidth-533,450,screenWidth,screenHeight);
                                if(cnt%2==1)
                                    outtextxy(screenWidth-400,470," Player 1");
                                else
                                    outtextxy(screenWidth-400,470," Player 2");
                            }
                            else
                            {
                                settextstyle(BOLD_FONT,HORIZ_DIR,5);
                                readimagefile("castigator.jpg",screenWidth-533,450,screenWidth,screenHeight);
                                if(cnt%2==1)

                                        outtextxy(screenWidth-400,470,"Jucator 1");
                                else
                                    outtextxy(screenWidth-400,470,"Jucator 2");
                            }
                            blocat=true;
                        }
                        setcolor(MAGENTA);
                        if(ln1==0 || cn1 == 0|| ln1 == numar +1 || cn1 == numar+1)
                        {
                            if(language==1)
                            {
                                settextstyle(BOLD_FONT,HORIZ_DIR,4);
                                readimagefile("loser.jpg",screenWidth-533,450,screenWidth,screenHeight);
                                if(cnt%2==0)
                                    outtextxy(screenWidth-380,510," Player 2");
                                else
                                    outtextxy(screenWidth-380,510," Player 1");

                            }
                            else
                            {
                                settextstyle(BOLD_FONT,HORIZ_DIR,4);
                                readimagefile("pierzator.jpg",screenWidth-533,450,screenWidth,screenHeight);
                                if(cnt%2==0)

                                        outtextxy(screenWidth-380,510,"Jucator 2");

                                else
                                        outtextxy(screenWidth-380,510,"Jucator 1");
                            }
                            blocat=true;

                        }

                        if(ln1 < 0 || cn1 < 0)
                        {
                            if(language==1)
                                readimagefile("error.jpg",screenWidth-533,450,screenWidth,screenHeight);
                            else
                                readimagefile("eroare.jpg",screenWidth-533,450,screenWidth,screenHeight);
                            blocat=true;
                        }


                        if(blocat==false)
                            contur_piesa_urmatoare(ln1,cn1);

                    }

                }
                else
                {
                    Beep(200,200);
                    lv=lv1;
                    cv=cv1;
                    la=la1;
                    ca=ca1;
                }
            }
        }
    }
    while (!alegere_corecta);
    return ok;
}

bool jocFinal()
{
    return ln==0 || cn==0;
}




void apeleazajoc()
{
    initTabla();
    matriceTabla();
    prezentare_piese();
    do
    {
        piesaAleasa=0;
        do
        {
            alegePiesa(piesaAleasa);

        }
        while (piesaAleasa==0);
        punerePiesa();
    }
    while (!jocFinal());
}

void INAPOI();

void NIVELE()
{
    cleardevice();
    desenNivel();
    int stop;
    do
    {
        int nivel_apasat=NivelAles();
        if (nivel_apasat!=0)
        {
            if(nivel_apasat==1)
                numar=4;
            if(nivel_apasat==2)
                numar=5;
            else if(nivel_apasat==3)
                numar=6;
            else if(nivel_apasat==4)
                numar=7;
            else if(nivel_apasat==5)
                numar=8;
            cleardevice();
            apeleazajoc();
        }
        stop=nivel_apasat;
    }
    while(stop!=6);
}

void INAPOI()
{
    int x,y;
    int stop=1;
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
            if (x>=10 && x<=140 && y>=10 && y<=50)
            {
                stop=0;
                deseneazaMeniul();
            }
        }
    }
    while(stop!=0);
}

void INSTRUCTIUNI()
{
    setcolor(MAGENTA);
    settextstyle(BOLD_FONT,HORIZ_DIR,6);
    readimagefile("instructiuni.jpg",0,0,screenWidth,screenHeight);
    if(language==1)
        readimagefile("instr1.jpg",100,100,screenWidth-100,screenHeight-100);
    else
        readimagefile("instr2.jpg",100,100,screenWidth-100,screenHeight-100);
    if(language==1)
        outtextxy(screenWidth/2-200,30,"INSTRUCTIONS");
    else
        outtextxy(screenWidth/2-200,30,"INSTRUCTIUNI");
    setfillstyle(SOLID_FILL,BLACK);
    setcolor(LIGHTCYAN);
    bar(10,10,135,50);
    settextstyle(BOLD_FONT,HORIZ_DIR,4);
    rectangle(10,10,135,50);
    if(language==1)
        outtextxy(15,15," BACK");
    else
        outtextxy(15,15,"INAPOI");
}

void CREATORI()
{
    readimagefile("creatori-bckgrnd.jpg",0,0,screenWidth,screenHeight);

    setfillstyle(SOLID_FILL,BLACK);
    bar(150,100,650,780);
    bar(850,100,1350,780);
    setcolor(LIGHTCYAN);
    rectangle(150,100,650,780);
    rectangle(151,99,649,779);
    rectangle(850,100,1350,780);
    rectangle(849,99,1349,779);

    bar(10,10,135,50);
    rectangle(10,10,135,50);
    settextstyle(BOLD_FONT,HORIZ_DIR,4);
    if(language==1)
        outtextxy(15,15," BACK");
    else
        outtextxy(15,15,"INAPOI");

    readimagefile("creator11.jpg",200,140,600,540);
    readimagefile("creator22.jpg",900,140,1300,540);

    setcolor(CYAN);
    settextstyle(BOLD_FONT,HORIZ_DIR,3);
    outtextxy(200,550,"NAME: Danca Gabriel");
    outtextxy(200,570,"UNIVERSITY: FII UAIC");
    outtextxy(200,590,"DISCORD: @pinguinnervos");
    outtextxy(200,610,"Personal insight:");
    outtextxy(260,640,"let coffee = new Coffee();");
    outtextxy(260,660,"if(coffee.isEmpty())");
    outtextxy(280,680,"coffee.refill();");
    outtextxy(260,700,"else");
    outtextxy(280,720,"coffee.drink();");

    settextstyle(BOLD_FONT,HORIZ_DIR,3);
    outtextxy(900,550,"NAME: Ilisei Daria-Stefania");
    outtextxy(900,570,"UNIVERSITY: FII UAIC");
    outtextxy(900,590,"DISCORD: @daria27");
    outtextxy(900,610,"Personal insight:");
    settextstyle(BOLD_FONT,HORIZ_DIR,2);
    outtextxy(940,630,"while(alive)");
    outtextxy(960,650,"{");
    outtextxy(980,670,"music();");
    outtextxy(980,690,"code();");
    outtextxy(980,710,"pet_dogs();");
    outtextxy(980,730,"sleep();");
    outtextxy(960,750,"}");
}

//////////setari///////////////////
int setareAles()
{
    int i;
    punct pp;
    if (ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        pp.x=mousex();
        pp.y=mousey();
        for (i=1; i<=nrSetari; i++)
            if (apartine(pp,S[i].D))
                return i;
            else if(pp.x>=10 && pp.x<=140 && pp.y>=10 && pp.y<=50)
                MENIU();
    }
    return 0;
}

void deseneazaSETARI()
{
    readimagefile("setari.jpg",0,0,screenWidth,screenHeight);
    setfillstyle(SOLID_FILL,BLACK);
    setcolor(LIGHTCYAN);
    bar(10,10,135,50);
    rectangle(10,10,135,50);
    settextstyle(BOLD_FONT,HORIZ_DIR,4);
    if(language==1)
        outtextxy(15,15," BACK");
    else
        outtextxy(15,15,"INAPOI");

    setfillstyle(SOLID_FILL,LIGHTCYAN);
    int i;
    for (i=1; i<=4; i++)
    {
        //stanga sus
        S[i].D.SS.x=screenWidth/4-170;//cat la stanga de mijloc incepe
        S[i].D.SS.y=screenHeight/4-100+i*100;//spatiul intre butoane
        //dreapta jos
        S[i].D.DJ.x=screenWidth/4+170;//cat la dreapta se duce(200 ca sa cuprinda tot cuvantul instructiune)
        S[i].D.DJ.y=S[i].D.SS.y+70;
        settextstyle(BOLD_FONT,HORIZ_DIR,5);
        setcolor(MAGENTA);
        switch(i)
        {
        case 1:
            if(language==1)
                strcpy(S[i].text,"  MODEL I  ");
            else
                strcpy(S[i].text,"  MODELUL 1");
            setfillstyle(SOLID_FILL,LIGHTGRAY);
            bar(S[i].D.DJ.x+115,S[i].D.SS.y,S[i].D.DJ.x+285,S[i].D.DJ.y);
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(S[i].D.DJ.x+320,S[i].D.SS.y,S[i].D.DJ.x+490,S[i].D.DJ.y);
            break;
        case 2:
            if(language==1)
                strcpy(S[i].text,"  MODEL II  ");
            else
                strcpy(S[i].text,"  MODELUL 2");
            setfillstyle(SOLID_FILL,LIGHTMAGENTA);
            bar(S[i].D.DJ.x+115,S[i].D.SS.y,S[i].D.DJ.x+285,S[i].D.DJ.y);
            setfillstyle(SOLID_FILL,MAGENTA);
            bar(S[i].D.DJ.x+320,S[i].D.SS.y,S[i].D.DJ.x+490,S[i].D.DJ.y);
            break;
        case 3:
            if(language==1)
                strcpy(S[i].text,"  MODEL III ");
            else
                strcpy(S[i].text,"  MODELUL 3");
            setfillstyle(SOLID_FILL,CYAN);
            bar(S[i].D.DJ.x+115,S[i].D.SS.y,S[i].D.DJ.x+285,S[i].D.DJ.y);
            setfillstyle(SOLID_FILL,LIGHTCYAN);
            bar(S[i].D.DJ.x+320,S[i].D.SS.y,S[i].D.DJ.x+490,S[i].D.DJ.y);
            break;
        case 4:
            if(language==1)
                strcpy(S[i].text,"  MODEL IV ");
            else
                strcpy(S[i].text,"  MODELUL 4");
            setfillstyle(SOLID_FILL,DARKGRAY);
            bar(S[i].D.DJ.x+115,S[i].D.SS.y,S[i].D.DJ.x+285,S[i].D.DJ.y);
            setfillstyle(SOLID_FILL,LIGHTGREEN);
            bar(S[i].D.DJ.x+320,S[i].D.SS.y,S[i].D.DJ.x+490,S[i].D.DJ.y);
            break;
        }
        setcolor(CYAN);
        rectangle(S[i].D.SS.x,S[i].D.SS.y,S[i].D.DJ.x,S[i].D.DJ.y);
        outtextxy(S[i].D.SS.x+2,S[i].D.SS.y+15,S[i].text);
    }

    settextstyle(BOLD_FONT,HORIZ_DIR,4);
    if(language==1)
    {
        outtextxy(S[1].D.SS.x,S[1].D.SS.y-50,"SELECT THEME:");
        outtextxy(S[1].D.DJ.x+110,S[1].D.SS.y-50,"GAME BOARD");
        outtextxy(S[1].D.DJ.x+340,S[1].D.SS.y-50,"SQUARES");
    }
    else
    {
        outtextxy(S[1].D.SS.x,S[1].D.SS.y-50,"SELECTEAZA TEMA:");
        outtextxy(S[1].D.DJ.x+110,S[1].D.SS.y-50,"TABLA JOC");
        outtextxy(S[1].D.DJ.x+340,S[1].D.SS.y-50,"CAREURI");
    }
    int k=1;
    for(i=5; i<=8; i++)
    {
        S[i].D.SS.x=-270+k*350;//cat la stanga de mijloc incepe
        S[i].D.SS.y=screenHeight-140;//spatiul intre butoane
        S[i].D.DJ.x=S[i].D.SS.x+320;//cat la dreapta se duce(200 ca sa cuprinda tot cuvantul instructiune)
        S[i].D.DJ.y=S[i].D.SS.y+100;

        k++;

        settextstyle(BOLD_FONT,HORIZ_DIR,5);
        setcolor(MAGENTA);
        switch(i)
        {
        case 5:
            if(language==1)
                strcpy(S[i].text," MUSIC ON");
            else
                strcpy(S[i].text," MUZICA ON");
            break;
        case 6:
            if(language==1)
                strcpy(S[i].text," MUSIC OFF");
            else
                strcpy(S[i].text,"MUZICA OFF");
            break;
        case 7:
            if(language==1)
                strcpy(S[i].text," ROMANIAN");
            else
                strcpy(S[i].text,"  ROMANA ");
            break;
        case 8:
            if(language==1)
                strcpy(S[i].text," ENGLISH");
            else
                strcpy(S[i].text," ENGLEZA");
            break;
        }
        setcolor(CYAN);
        outtextxy(S[i].D.SS.x+35,S[i].D.SS.y+10,S[i].text);
        //setcolor(YELLOW);
        //line(S[i].D.SS.x,S[i].D.SS.y,S[i].D.DJ.x,S[i].D.DJ.y);
    }
}

int vai=0; // la schimbarea limbii, pastreaza afisarea chosen/ales

int theme(int nr)
{
    setfillstyle(SOLID_FILL,BLACK);
    bar(1090,200,1310,605);
    switch(nr)
    {
    case 1:
        vai=1;
        rectangle(1100,220,1300,280);
        if(language==1)
            outtextxy(1125,230,"CHOSEN");
        else
            outtextxy(1125,230," ALES");
        break;
    case 2:
        vai=2;
        rectangle(1100,320,1300,380);
        if(language==1)
            outtextxy(1125,330,"CHOSEN");
        else
            outtextxy(1125,330," ALES");
        break;
    case 3:
        vai=3;
        rectangle(1100,420,1300,480);
        if(language==1)
            outtextxy(1125,430,"CHOSEN");
        else
            outtextxy(1125,430," ALES");
        break;
    case 4:
        vai=4;
        rectangle(1100,520,1300,580);
        if(language==1)
            outtextxy(1125,530,"CHOSEN");
        else
            outtextxy(1125,530," ALES");
        break;
    }
}

void SETARI()
{
    deseneazaSETARI();
    int comanda, butonul_apasat;
    int ahhh=0;
    do
    {
        butonul_apasat=setareAles();
        if (butonul_apasat!=0)
        {
            if(butonul_apasat==1)
                ahhh=1, bar(1090,200,1310,605),theme(1),model_tabla=1,ahhh=0;
            if(butonul_apasat==2)
                ahhh=1, bar(1090,200,1310,605),theme(2),model_tabla=2,ahhh=0;
            if(butonul_apasat==3)
                ahhh=1, bar(1090,200,1310,605),theme(3),model_tabla=3,ahhh=0;
            if(butonul_apasat==4)
                ahhh=1, bar(1090,200,1310,605),theme(4),model_tabla=4,ahhh=0;

            if(butonul_apasat==5)
                ahhh=1,PlaySound("song.wav",NULL,SND_ASYNC|SND_LOOP),ahhh=0;
            if(butonul_apasat==6)
                ahhh=1,PlaySound(NULL,NULL,SND_PURGE),ahhh=0;
            if(butonul_apasat==7)
                ahhh=1,language=0,deseneazaSETARI(),theme(vai),ahhh=0;
            if(butonul_apasat==8)
                ahhh=1,language=1,deseneazaSETARI(),theme(vai),ahhh=0;
            comanda=butonul_apasat;
        }
    }
    while (comanda!=9);
}
/////////////////setari/////////////////////
void MENIU()
{
    deseneazaMeniul();
    int comanda, butonul_apasat;
    int ahhh=0;//utilizata cand ne intoarcem la meniu (BACK)
    do
    {
        butonul_apasat=butonAles();
        if (butonul_apasat!=0 && ahhh==0)
        {
            cleardevice();
            if(butonul_apasat==1)
                ahhh=1,NIVELE(),ahhh=0;
            if(butonul_apasat==2)
                ahhh=1,INSTRUCTIUNI(),INAPOI(),ahhh=0;
            if(butonul_apasat==3)
                ahhh=1,CREATORI(),INAPOI(),ahhh=0;
            if(butonul_apasat==4)
                ahhh=1,SETARI(),ahhh=0;
            comanda=butonul_apasat;
        }
    }
    while (comanda!=5);
    closegraph();
}

int main()
{
    initwindow(screenWidth,screenHeight,"Coltul Negru");
   // beginning();
    //oading_Game();
    MENIU();
    cout<<getmaxx()<<endl<<getmaxy()<<endl;
    return 0;
}
