#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int elmaslar[5];
int muhafizlar[5];

void elmasolustur(){
    int i,j;
    int r;
    for(i=0;i<5;i++)
    {
        r=rand()%99;
        if(r==24)
        {
            elmasolustur();
            break;
        }
        if(i==0)
        {
            elmaslar[i]=r;
        }
        else
        {
            for(j=0;j<i;j++)
            {
                if(elmaslar[j]==r)
                {
                    elmasolustur();
                    break;
                }
                else
                {
                    elmaslar[i]=r;
                    break;
                }
            }
        }
    }
}

void muhafizolustur(int i){
    int j;
    int m[8];
    int e,kontrol=0;
    int r,k,l;

    e=elmaslar[i];
    m[0]=e-11;
    m[1]=e-10;
    m[2]=e-9;
    m[3]=e-1;
    m[4]=e+1;
    m[5]=e+9;
    m[6]=e+10;
    m[7]=e+11;

    r=rand()%7;

    if(m[r]==24 || m[r]<0 || m[r]>99)
    {
        muhafizolustur(i);
        return;
    }
    for(k=0;k<5;k++)
    {
        if(elmaslar[k]==m[r])
        {
            kontrol=1;
            break;
        }
    }
    if(kontrol==1)
    {
        kontrol=0;
        muhafizolustur(i);
        return;
    }
    else if(i==0)
    {
        muhafizlar[i]=m[r];
    }
    else
    {
        for(l=0;l<i;l++)
        {
            if(muhafizlar[l]==m[r])
            {
                muhafizolustur(i);
                break;
            }
            else
            {
                muhafizlar[i]=m[r];
                break;
            }
        }

    }

  //  printf("M:%d\n",muhafizlar[i]);
}
      


int main(int argc, const char * argv[]) {
    int a,b,Ka=2,Kb=4,Kd,can=3,toplamElmas=0;
    char Kc;
    
    int toplananElmaslar[5];
    int i;
    unsigned seed=time(NULL);
    srand(seed);
    elmasolustur();
    for(i=0;i<5;i++)
    {
    
        muhafizolustur(i);
    }
    
   // printf("Elmaslar \n");
    for(i=0;i<5;i++)
    {
        //printf(" %d \n",elmaslar[i]);
    }
    while(1) {
    etiket:;
        for(a=0;a<10;a++){
            for(b=0;b<10;b++){
                if(a==Ka && b==Kb)
                {
                    printf(" K ");
                }
                else
                {
                    printf("-- ");
                }
               
            }
            printf("\n");
        }
        Kd=(Ka*10)+Kb;
       // printf("Kd:%d, Ka:%d ,Kb:%d\n",Kd,Ka,Kb);
        for(i=0;i<5;i++)
        {
            int Ea,Eb;
            Ea=elmaslar[i]/10;
            Eb=elmaslar[i]%10;
            if(abs(Ea-Ka)+abs(Eb-Kb)!=0)
            {
                printf("%d. Elmasa Mesafe: %d \n",i+1,abs(Ea-Ka)+abs(Eb-Kb));
            }
            else
            {
                printf("%d. Elmas Toplandı \n",i+1);
            }
            if(Kd==elmaslar[i] && Kd!=toplananElmaslar[i])
            {
                printf("Elmas Kazandiniz\n");
                toplamElmas=toplamElmas+1;
                toplananElmaslar[i]=elmaslar[i];
            }
            if(Kd==muhafizlar[i] )
            {
                printf("MUHAFiZA YAKALANDiNiZ\n");
                can=can-1;
                Ka=2;
                Kb=4;
                goto etiket;
            }
           /* if(elmaslar[i]==0abs(Ea-Ka)+abs(Eb-Kb)==0)
            {
                printf("%d. Elmasa mesafe: TOPLANDI",i+1);
            }*/
        }
        printf("Toplanan elmas sayisi:%d\n",toplamElmas);
        printf("Kalan can:%d\n",can);
            if(toplamElmas==5)
            {
                printf("KAZANDiNiZ\n");
                break;
            }
        if(can<=0 )
        {
            printf("KAYBETTİNİZ\n");
            break;
        }
            printf("Oyuncuyu hareket ettiriniz(w-a-s-d ile):\n ");
            scanf(" %c",&Kc);
            if(Kc=='w')
            {
                if(Kd>9 )
                {
                    Ka--;
                }
            }
        
            else if(Kc=='s')
            {
                if(Kd<=89)
                {
                    Ka++;
                    
                }
            }
            else if(Kc=='d')
            {
                if((Kd+1)/10==((Ka*10)+Kb)/10)
                {
                    Kb++;
                }
            }
            else if(Kc=='a')
            {
                if(Kd!=0 && (Kd-1)/10==((Ka*10)+Kb)/10)
                {
                    Kb--;
                }
            }
        }
     
     return 0;
     }
