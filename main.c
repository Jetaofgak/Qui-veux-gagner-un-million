#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>


// MIS A JOUR

char rejouer;
char inputReponse = '0';
char inputBonus = '0';
int echouer = 0;
int abandon = 0;
int gain[]={0,100,200,500,1000,2000,3000,5000,10000,20000,200000,500000,1000000};
int prixNumero = 1;
int Jswitch=1;
int J5050=1;
int JPublic=1;
int temoinRNG = 1;
int temoinRNGBarrage = 1;
char RepOuBonus = '0';
char lesQuestion[][1000]={
 "Question 1: Qui a chanter despacito?"
,"Question 2: Ciao est un salut en quel langue?"
,"Question 3: Quel est le gout principal de la foret noire?"
,"Question 4: Quel est le nom de la première serie de Riot Games?"
,"Question 5: Charles Dickens a ecrit un roman intitulée Oliver..."
,"Question 6: Quel est le titre complet de la comédie de Molière ?"
,"Question 7: Parmis ses cartes iconique, quel est celle qui s'est vendu au prix le plus élevée?"
,"Question 8: Quel variété de pomme de terre n'existe pas?"
,"Question 9: Quel est le pourcentage de personnes intolérente au lactose?"
,"Question 10: Qui a ecrit 1984?"
,"Question 11: Qu'est que le r/place sur reddit?"
,"Question 12: Qu'est qui est jaune et qui attend"};
int numeroQuestion = 0;
char lesQuestionBis [][1000]={
"Question 1: En amérique, quel viande est utilisé pour le buffalo wings?"
,"Question 2: Qui a racheter le reseau social Twitter pour 44 milliard de dollars"
,"Question 3: En physique, lequel de ses objet n'est pas une source de lumière"
,"Question 4: En science qu'appelle t'on la base de comparaison lors d'une experience"
,"Question 5: Quel est la plus grande plateforme de diffusion en streaming qui n'est pas youtube"
,"Question 6: Bim Badabim bim badaboum..."
,"Question 7: Quel est le jeu de carte virtuelle le plus populaire"
,"Question 8: Parmis ses article wikipédia Lequel est le plus consulté de 2020"
,"Question 9: Quel est le pays ou la glace napolitaine a été inventé?"
,"Question 10: Que signifie Mein Kampf"
,"Question 11: Qu'est que discord?"
,"Question 12: Qu'elle est l'une des réponse parmis celle de la question que vous vener de changer"};
char lesReponses[][90] = {
 "|A: Luis Fonsi|"
,"|B: Ricky Martin|"
,"|C: Carlos Ponce|"
,"|D: Don Quichotte|"

,"|A: Greque|"
,"|B: Espagnol|"
,"|C: Italien|"
,"|D: Français|"

,"|A :Le nougat|"
,"|B :Le chocolat|"
,"|C :Le citron|"
,"|D :La vanille|"

,"|A : Summoners|"
,"|B : Noxus|"
,"|C : Arcane|"
,"|D : Sentinels|"

,"|A : Law|"
,"|B : Dickens|"
,"|C : Coffee|"
,"|D : Twist|"

,"|A: L'Avare ou la théorie de l'économe|"
,"|B: L'avare ou la Marmite moderne|"
,"|C: L'Avare ou l'école du mensonge|"
,"|D: L'Avare ou l'impossibilité de vivre près de ses sous|"

,"|A: Dragon Aux Yeux Bleu|"
,"|B: Black lotus|"
,"|C: Draceaufeu première edition|"
,"|D: Pikachu Illustrator|"

,"|A: Josette|"
,"|B: Obama|"
,"|C: Nicola|"
,"|D: Charlotte|"

,"|A: 80%|"
,"|B: 60%|"
,"|C: 40%|"
,"|D: 20%|"

,"|A : George Orwell|"
,"|B : Jack London|"
,"|C : J.K Rowling|"
,"|D : John Steinbeck|"

,"|A : Un forum permanant|"
,"|B : Une place de discussion occasionel|"
,"|C : Une canvas ou l'ont peux poser des pixel|"
,"|D : Un forum qui fait offic de jeu|"

,"|A : Le tournesol|"
,"|B : Le soleil|"
,"|C : Le jaune d'oeuf|"
,"|D : Jonathan|"
};
char lesReponsesBis[][90] ={
 "|A: Buffle|"
,"|B: Poulet|"
,"|C: Dinde|"
,"|D: Boeuf|"

,"|A: Elon Musk|"
,"|B: Mark Zuckerberg|"
,"|C: Bill Gates|"
,"|D: Jeff Bezos|"

,"|A: Lampe depoche|"
,"|B: Miroire|"
,"|C: Ampoule|"
,"|D: Projecteur|"

,"|A: Test|"
,"|B: Arbitre|"
,"|C: Témoins|"
,"|D: Avocat|"

,"|A: Facebook|"
,"|B: Mixer|"
,"|C: Theta Tv|"
,"|D: Twitch|"

,"|A: Ils sont beaux|"
,"|B: Ils sont saint|"
,"|C: Ils sont cools |"
,"|D: Ils sont oof|"

,"|A: Magic The Gathering Arena|"
,"|B: Hearthstone|"
,"|C: Legend of Runterra|"
,"|D: Pokémon TCGO|"

,"|A: Christiano ronaldo|"
,"|B: Etats-Unis|"
,"|C: Pandémie de Covid-19 en France|"
,"|D: Donald Trump|"

,"|A: Espagne|"
,"|B: France|"
,"|C: USA|"
,"|D: Italie|"

,"|A : Mon combat|"
,"|B: Ma vie|"
,"|C: Mon future|"
,"|D: Mon espoire|"

,"|A : Appli d'appel|"
,"|B: Appli de streaming|"
,"|C: Appli de communication|"
,"|D: Tous ce qui est proposé|"

,"|A : Poire|"
,"|B: Jaune d'oeuf|"
,"|C: Citron|"
,"|D: Poussin|"
};
int DSwitch = 0;
int Dpublic = 0;
int D5050 = 0;
int rng1,rng2,rng3,rng4;
int rngBarrage = 0;
int barrage1 = 0;
int barrage2 = 0;
int barrage3 = 0;

void BonusRNG()
{
    if(temoinRNGBarrage == 1)
    {

    do
    {
        rngBarrage = rand()%(3-1+1) + 1;
    }while (rngBarrage == 3);

    if(rngBarrage == 1)
    {
        barrage1 = 1;
        while (rngBarrage == 1)
        {
            rngBarrage = rand()%(3-1+1) + 1;
        }
        if(rngBarrage == 2)
        {
            barrage2 = 1;
            barrage3 = 0;
        }
        else if (rngBarrage == 3)
        {
            barrage2 = 0;
            barrage3 = 1;
        }
    }

    else if(rngBarrage == 2)
    {
        barrage1 = 0;
        barrage2 = 1;
        barrage3 = 1;
    }
        temoinRNGBarrage = 0;
    }
}
void RNG()
{
         rng1 = rand()%101;
        rng2 = rand()%(101-rng1);
        if(rng2 <0)
            rng2 = 0;
        rng3 = rand()%(101-rng2-rng1);
        if(rng3 <0)
            rng3 = 0;
        rng4 = rand()%(101-rng3-rng2-rng1);
        if(rng4 <0)
            rng4 = 0;
        temoinRNG = 0;
}
void VariableRetourneAZero()
{
    echouer = 0;
    abandon = 0;
    prixNumero = 1;
    Jswitch = 1;
    J5050 = 1;
    JPublic = 1;
    numeroQuestion = 0;
    temoinRNG = 1;
    temoinRNGBarrage = 1;
}
void Bonus()
{
    if(inputBonus == 'S' && Jswitch == 1)
    {
        DSwitch = 1;
        Jswitch = 0;
    }
    else if(inputBonus == 'M' && J5050 == 1)
    {
        D5050 = 1;
        J5050 = 0;
    }
    else if (inputBonus == 'P' && JPublic == 1)
    {
        Dpublic = 1;
        JPublic = 0;
    }
}
void QuestionBis(int numBis)
{
    printf("|  %s  |\n\n\n\n",lesQuestionBis[numBis]);
}
void Question(int num)
{
 printf("|  %s  |\n\n\n\n",lesQuestion[num]);

}
void BonneReponse()
{
    printf("Juste!\nTaper entrée pour continuer \n");
    prixNumero++;
    fflush(stdin);
    getch();
}
void FausseReponse()
{

        if(prixNumero >= 2)
        {
            printf("Faux!\nTaper entrée pour continuer \n");
            prixNumero--;
            fflush(stdin);
            getchar();
        }
        else
        {
            echouer = 1;
        }
}

void ReponsePossibleAffiche()
{
    BonusRNG();

    switch(numeroQuestion)
    {
    case 0:
        BonusRNG();
        if(Dpublic == 0)
        {

        printf("%s    ",lesReponses[0]);
        if(barrage1 != 1 || D5050 != 1)
        printf("%s    \n",lesReponses[1]);


       if(barrage2 != 1 || D5050 != 1 )
        printf("%s     ",lesReponses[2]);


        if(barrage3 != 1 || D5050 != 1 )
        printf("%s     \n\n\n",lesReponses[3]);

        }
        else if(Dpublic == 1)
        {
        if(temoinRNG == 1)
        RNG();
        printf("%s  %d %%  ",lesReponses[0],rng1);
        if(barrage1 != 1 || D5050 != 1)
        printf("%s  %d %%\n",lesReponses[1],rng2);
        if(barrage2 != 1 || D5050 != 1 )
        printf("%s  %d %% ",lesReponses[2],rng3);
        if(barrage3 != 1 || D5050 != 1 )
        printf("%s  %d %%\n\n\n",lesReponses[3],rng4);
        }
        break;

    case 1:
        if(Dpublic == 0)
        {

        if(barrage1 != 1 || D5050 != 1)
        printf("%s   ",lesReponses[4]);
        if(barrage2 != 1 || D5050 != 1)
        printf("%s  \n",lesReponses[5]);
        printf("%s   ",lesReponses[6]);
        if(barrage3 != 1 || D5050 != 1)
        printf("%s   \n\n\n",lesReponses[7]);
        }
        else if(Dpublic == 1)
        {
            if(temoinRNG == 1)
          RNG();

	if(barrage1 != 1 || D5050 != 1)
        printf("%s  %d %%  ",lesReponses[4],rng1);
	if(barrage2 != 1 || D5050 != 1)
        printf("%s  %d %%   \n",lesReponses[5],rng2);
        printf("%s  %d %%   ",lesReponses[6],rng3);
	if(barrage3 != 1 || D5050 != 1)
        printf("%s   %d %%  \n\n\n",lesReponses[7],rng4);
        }
        break;
    case 2:
        if(Dpublic == 0)
        {


        if(barrage1 != 1 || D5050 != 1)
        printf("%s    ",lesReponses[8]);
        printf("%s     \n",lesReponses[9]);
        if(barrage2 != 1 || D5050 != 1)
        printf("%s     ",lesReponses[10]);
        if(barrage3 != 1 || D5050 != 1)
        printf("%s     \n\n\n",lesReponses[11]);
        }
        else if(Dpublic == 1)
        {
                if(temoinRNG == 1)
            RNG();

	if(barrage1 != 1 || D5050 != 1)
        printf("%s  %d %%  ",lesReponses[8],rng1);
        printf("%s  %d %%   \n",lesReponses[9],rng2);
	if(barrage2 != 1 || D5050 != 1)
        printf("%s  %d %%   ",lesReponses[10],rng3);
	if(barrage3 != 1 || D5050 != 1)
        printf("%s  %d %%   \n\n\n",lesReponses[11],rng4);
        }
        break;
    case 3:
        if(Dpublic == 0)
        {

	if(barrage1 != 1 || D5050 != 1)
        printf("%s    ",lesReponses[12]);
	if(barrage2 != 1 || D5050 != 1)
        printf("%s     \n",lesReponses[13]);
        printf("%s     ",lesReponses[14]);
	if(barrage3 != 1 || D5050 != 1)
        printf("%s     \n\n\n",lesReponses[15]);
        }
        else if(Dpublic == 1)
        {
                if(temoinRNG == 1)
            RNG();

	if(barrage1 != 1 || D5050 != 1)
        printf("%s    ",lesReponses[12],rng1);
	if(barrage2 != 1 || D5050 != 1)
        printf("%s     \n",lesReponses[13],rng2);
        printf("%s     ",lesReponses[14],rng3);
	if(barrage3 != 1 || D5050 != 1)
        printf("%s     \n\n\n",lesReponses[15],rng4);
        }
        break;
    case 4:
        if(Dpublic == 0)
        {

	if(barrage1 != 1 || D5050 != 1)
        printf("%s    ",lesReponses[16]);
	if(barrage2 != 1 || D5050 != 1)
        printf("%s     \n",lesReponses[17]);
	if(barrage3 != 1 || D5050 != 1)
        printf("%s     ",lesReponses[18]);
        printf("%s     \n\n\n",lesReponses[19]);
        }
        else if(Dpublic == 1)
        {
                if(temoinRNG == 1)
            RNG();

	if(barrage1 != 1 || D5050 != 1)
        printf("%s  %d %%  ",lesReponses[16],rng1);
	if(barrage2 != 1 || D5050 != 1)
        printf("%s  %d %%   \n",lesReponses[17],rng2);
	if(barrage3 != 1 || D5050 != 1)
        printf("%s  %d %%   ",lesReponses[18],rng3);
        printf("%s  %d %%   \n\n\n",lesReponses[19],rng4);
        }
        break;
    case 5:
        if(Dpublic == 0)
        {

	if(barrage1 != 1 || D5050 != 1)
        printf("%s    ",lesReponses[20]);
	if(barrage2 != 1 || D5050 != 1)
        printf("%s     \n",lesReponses[21]);
        printf("%s     ",lesReponses[22]);
	if(barrage3 != 1 || D5050 != 1)
        printf("%s     \n\n\n",lesReponses[23]);
        }
        else if(Dpublic == 1)
        {
                if(temoinRNG == 1)
            RNG();

	if(barrage1 != 1 || D5050 != 1)
        printf("%s  %d %%  ",lesReponses[20],rng1);
	if(barrage2 != 1 || D5050 != 1)
        printf("%s  %d %%   \n",lesReponses[21],rng2);
        printf("%s  %d %%   ",lesReponses[22],rng3);
	if(barrage3 != 1 || D5050 != 1)
        printf("%s  %d %%   \n\n\n",lesReponses[23],rng4);
        }
        break;
    case 6:
        if(Dpublic == 0)
        {

	if(barrage1 != 1 || D5050 != 1)
        printf("%s    ",lesReponses[24]);
	if(barrage2 != 1 || D5050 != 1)
        printf("%s     \n",lesReponses[25]);
	if(barrage3 != 1 || D5050 != 1)
        printf("%s     ",lesReponses[26]);
        printf("%s     \n\n\n",lesReponses[27]);
        }
        else if(Dpublic == 1)
        {
                if(temoinRNG == 1)
           RNG();

	if(barrage1 != 1 || D5050 != 1)
        printf("%s  %d %%  ",lesReponses[24],rng1);
	if(barrage2 != 1 || D5050 != 1)
        printf("%s  %d %%   \n",lesReponses[25],rng2);
	if(barrage3 != 1 || D5050 != 1)
        printf("%s  %d %%   ",lesReponses[26],rng3);
        printf("%s  %d %%   \n\n\n",lesReponses[27],rng4);
        }
        break;
    case 7:
        if(Dpublic == 0)
        {

        printf("%s   ",lesReponses[28]);

	if(barrage1 != 1 || D5050 != 1)
        printf("%s    \n",lesReponses[29]);
	if(barrage2 != 1 || D5050 != 1)
        printf("%s    ",lesReponses[30]);
	if(barrage3 != 1 || D5050 != 1)
        printf("%s    \n\n\n",lesReponses[31]);
        }
        else if(Dpublic == 1)
        {
                if(temoinRNG == 1)
           RNG();

        printf("%s  %d %%  ",lesReponses[28],rng1);
	if(barrage1 != 1 || D5050 != 1)
        printf("%s  %d %%   \n",lesReponses[29],rng2);
	if(barrage2 != 1 || D5050 != 1)
        printf("%s  %d %%   ",lesReponses[30],rng3);
	if(barrage3 != 1 || D5050 != 1)
        printf("%s  %d %%   \n\n\n",lesReponses[31],rng4);
        }
        break;
    case 8:
        if(Dpublic == 0)
        {

        printf("%s    ",lesReponses[32]);
	if(barrage1 != 1 || D5050 != 1)
        printf("%s     \n",lesReponses[33]);
	if(barrage2 != 1 || D5050 != 1)
        printf("%s     ",lesReponses[34]);
	if(barrage3 != 1 || D5050 != 1)
        printf("%s     \n\n\n",lesReponses[35]);
        }
        else if(Dpublic == 1)
        {
                if(temoinRNG == 1)
            RNG();

        printf("%s  %d %%    ",lesReponses[32],rng1);
	if(barrage1 != 1 || D5050 != 1)
        printf("%s  %d %%   \n",lesReponses[33],rng2);
	if(barrage2 != 1 || D5050 != 1)
        printf("%s  %d %%   ",lesReponses[34],rng3);
	if(barrage3 != 1 || D5050 != 1)
        printf("%s  %d %%   \n\n\n",lesReponses[35],rng4);
        }
        break;
    case 9:
        if(Dpublic == 0)
        {

        printf("%s    ",lesReponses[36]);
	if(barrage1 != 1 || D5050 != 1)
        printf("%s     \n",lesReponses[37]);
	if(barrage2 != 1 || D5050 != 1)
        printf("%s     ",lesReponses[38]);
	if(barrage3 != 1 || D5050 != 1)
        printf("%s     \n\n\n",lesReponses[39]);
        }
         else if(Dpublic == 1)
        {
                if(temoinRNG == 1)
            RNG();

        printf("%s  %d %%  ",lesReponses[36],rng1);
	if(barrage1 != 1 || D5050 != 1)
        printf("%s  %d %%   \n",lesReponses[37],rng2);
	if(barrage2 != 1 || D5050 != 1)
        printf("%s  %d %%   ",lesReponses[38],rng3);
	if(barrage3 != 1 || D5050 != 1)
        printf("%s  %d %%   \n\n\n",lesReponses[39],rng4);
        }
        break;
    case 10:
        if(Dpublic == 0)
        {

        printf("%s    ",lesReponses[40]);
	if(barrage1 != 1 || D5050 != 1)
        printf("%s     \n",lesReponses[41]);
	if(barrage2 != 1 || D5050 != 1)
        printf("%s     ",lesReponses[42]);
	if(barrage3 != 1 || D5050 != 1)
        printf("%s     \n\n\n",lesReponses[43]);
        }
        else if(Dpublic == 1)
        {
                if(temoinRNG == 1)
            RNG();

        printf("%s  %d %%  ",lesReponses[40],rng1);
	if(barrage1 != 1 || D5050 != 1)
        printf("%s  %d %%   \n",lesReponses[41],rng2);
	if(barrage2 != 1 || D5050 != 1)
        printf("%s  %d %%   ",lesReponses[42],rng3);
	if(barrage3 != 1 || D5050 != 1)
        printf("%s  %d %%   \n\n\n",lesReponses[43],rng4);
        }
        break;
    case 11:
        if(Dpublic == 0)
        {

	if(barrage1 != 1 || D5050 != 1)
        printf("%s    ",lesReponses[44]);
	if(barrage2 != 1 || D5050 != 1)
        printf("%s     \n",lesReponses[45]);
        printf("%s     ",lesReponses[46]);
	if(barrage3 != 1 || D5050 != 1)
        printf("%s     \n\n\n",lesReponses[47]);
        }
        else if(Dpublic == 1)
        {
                if(temoinRNG == 1)
            RNG();

	if(barrage1 != 1 || D5050 != 1)
        printf("%s  %d %%  ",lesReponses[44],rng1);
	if(barrage2 != 1 || D5050 != 1)
        printf("%s  %d %%   \n",lesReponses[45],rng2);
        printf("%s  %d %%   ",lesReponses[46],rng3);
	if(barrage3 != 1 || D5050 != 1)
        printf("%s  %d %%   \n\n\n",lesReponses[47],rng4);
        }
        break;
    case 12:
        if(Dpublic == 0)
        {

	if(barrage1 != 1 || D5050 != 1)
        printf("%s    ",lesReponses[48]);
	if(barrage2 != 1 || D5050 != 1)
        printf("%s     \n",lesReponses[49]);
	if(barrage3 != 1 || D5050 != 1)
        printf("%s     ",lesReponses[50]);
        printf("%s     \n\n\n",lesReponses[51]);
        }
        else if(Dpublic == 1)
        {
                if(temoinRNG == 1)
            RNG();

	if(barrage1 != 1 || D5050 != 1)
        printf("%s  %d %%  ",lesReponses[52],rng1);
	if(barrage2 != 1 || D5050 != 1)
        printf("%s  %d %%   \n",lesReponses[53],rng2);
	if(barrage3 != 1 || D5050 != 1)
        printf("%s  %d %%   ",lesReponses[54],rng3);
        printf("%s  %d %%   \n\n\n",lesReponses[55],rng4);
        }
        break;
    default: printf("ya un pb (ReponsePossibleAffiche");
    break;

    }


}

void ReponsePossibleAfficheBis()
{

    switch(numeroQuestion)
    {
    case 0:
        if(Dpublic == 0)
        {

 	if(barrage1 != 1 || D5050 != 1)
        printf("%s    ",lesReponsesBis[0]);
        printf("%s     \n",lesReponsesBis[1]);
 	if(barrage2 != 1 || D5050 != 1)
        printf("%s     ",lesReponsesBis[2]);
 	if(barrage3 != 1 || D5050 != 1)
        printf("%s     \n\n\n",lesReponsesBis[3]);
        }
        else if(Dpublic == 1)
        {
                if(temoinRNG == 1)
            RNG();

 	if(barrage1 != 1 || D5050 != 1)
        printf("%s  %d %%  ",lesReponsesBis[0],rng1);
        printf("%s  %d %%   \n",lesReponsesBis[1],rng2);
 	if(barrage2 != 1 || D5050 != 1)
        printf("%s  %d %%   ",lesReponsesBis[2],rng3);
 	if(barrage3 != 1 || D5050 != 1)
        printf("%s  %d %%   \n\n\n",lesReponsesBis[3],rng4);
        }
        break;
    case 1:
        if(Dpublic == 0)
        {

        printf("%s    ",lesReponsesBis[4]);
 	if(barrage1 != 1 || D5050 != 1)
        printf("%s     \n",lesReponsesBis[5]);
 	if(barrage2 != 1 || D5050 != 1)
        printf("%s     ",lesReponsesBis[6]);
 	if(barrage3 != 1 || D5050 != 1)
        printf("%s     \n\n\n",lesReponsesBis[7]);
        }
        else if(Dpublic == 1)
        {
                if(temoinRNG == 1)
             RNG();

        printf("%s  %d %%  ",lesReponsesBis[4],rng1);
 	if(barrage1 != 1 || D5050 != 1)
        printf("%s  %d %%   \n",lesReponsesBis[5],rng2);
 	if(barrage2 != 1 || D5050 != 1)
        printf("%s  %d %%   ",lesReponsesBis[6],rng3);
 	if(barrage3 != 1 || D5050 != 1)
        printf("%s  %d %%   \n\n\n",lesReponsesBis[7],rng4);
        }
        break;
    case 2:
        if(Dpublic == 0)
        {

 	if(barrage1 != 1 || D5050 != 1)
        printf("%s    ",lesReponsesBis[8]);
        printf("%s    \n",lesReponsesBis[9]);
 	if(barrage2 != 1 || D5050 != 1)
        printf("%s     ",lesReponsesBis[10]);
 	if(barrage3 != 1 || D5050 != 1)
        printf("%s     \n\n\n",lesReponsesBis[11]);
        }
        else if(Dpublic == 1)
        {
                if(temoinRNG == 1)
             RNG();

 	if(barrage1 != 1 || D5050 != 1)
        printf("%s  %d %%  ",lesReponsesBis[8],rng1);
        printf("%s  %d %%   \n",lesReponsesBis[9],rng2);
 	if(barrage2 != 1 || D5050 != 1)
        printf("%s  %d %%   ",lesReponsesBis[10],rng3);
 	if(barrage3 != 1 || D5050 != 1)
        printf("%s  %d %%   \n\n\n",lesReponsesBis[11],rng4);
        }
        break;
    case 3:
        if(Dpublic == 0)
        {

 	if(barrage1 != 1 || D5050 != 1)
        printf("%s    ",lesReponsesBis[12]);
 	if(barrage2 != 1 || D5050 != 1)
        printf("%s     \n",lesReponsesBis[13]);
        printf("%s     ",lesReponsesBis[14]);
 	if(barrage3 != 1 || D5050 != 1)
        printf("%s     \n\n\n",lesReponsesBis[15]);
        }
        else if(Dpublic == 1)
        {
                if(temoinRNG == 1)
            RNG();

 	if(barrage1 != 1 || D5050 != 1)
        printf("%s  %d %%  ",lesReponsesBis[12],rng1);
 	if(barrage2 != 1 || D5050 != 1)
        printf("%s  %d %%   \n",lesReponsesBis[13],rng2);
        printf("%s  %d %%   ",lesReponsesBis[14],rng3);
 	if(barrage3 != 1 || D5050 != 1)
        printf("%s  %d %%   \n\n\n",lesReponsesBis[15],rng4);
        }
        break;
    case 4:
        if(Dpublic == 0)
        {

 	if(barrage1 != 1 || D5050 != 1)
        printf("%s    ",lesReponsesBis[16]);
 	if(barrage2 != 1 || D5050 != 1)
        printf("%s     \n",lesReponsesBis[17]);
 	if(barrage3 != 1 || D5050 != 1)
        printf("%s     ",lesReponsesBis[18]);
        printf("%s     \n\n\n",lesReponsesBis[19]);
        }
        else if(Dpublic == 1)
        {
                if(temoinRNG == 1)
             RNG();

 	if(barrage1 != 1 || D5050 != 1)
        printf("%s  %d %%  ",lesReponsesBis[16],rng1);
 	if(barrage2 != 1 || D5050 != 1)
        printf("%s  %d %%   \n",lesReponsesBis[17],rng2);
 	if(barrage3 != 1 || D5050 != 1)
        printf("%s  %d %%   ",lesReponsesBis[18],rng3);
        printf("%s  %d %%   \n\n\n",lesReponsesBis[19],rng4);
        }
        break;
    case 5:
        if(Dpublic == 0)
        {

 	if(barrage1 != 1 || D5050 != 1)
        printf("%s    ",lesReponsesBis[20]);
 	if(barrage2 != 1 || D5050 != 1)
        printf("%s    \n",lesReponsesBis[21]);
        printf("%s     ",lesReponsesBis[22]);
 	if(barrage3 != 1 || D5050 != 1)
        printf("%s     \n\n\n",lesReponsesBis[23]);

        }
        else if(Dpublic == 1)
        {
                if(temoinRNG == 1)
             RNG();

 	if(barrage1 != 1 || D5050 != 1)
        printf("%s  %d %%  ",lesReponsesBis[20],rng1);
 	if(barrage2 != 1 || D5050 != 1)
        printf("%s  %d %%   \n",lesReponsesBis[21],rng2);
        printf("%s  %d %%   ",lesReponsesBis[22],rng3);
 	if(barrage3 != 1 || D5050 != 1)
        printf("%s  %d %%   \n\n\n",lesReponsesBis[23],rng4);
        }
        break;
    case 6:
        if(Dpublic == 0)
        {

 	if(barrage1 != 1 || D5050 != 1)
        printf("%s    ",lesReponsesBis[24]);
        printf("%s    \n",lesReponsesBis[25]);
 	if(barrage2 != 1 || D5050 != 1)
        printf("%s     ",lesReponsesBis[26]);
 	if(barrage3 != 1 || D5050 != 1)
        printf("%s     \n\n\n",lesReponsesBis[27]);

        }
        else if(Dpublic == 1)
        {
                if(temoinRNG == 1)
             RNG();

 	if(barrage1 != 1 || D5050 != 1)
        printf("%s  %d %%  ",lesReponsesBis[24],rng1);
        printf("%s  %d %%   \n",lesReponsesBis[25],rng2);
 	if(barrage2 != 1 || D5050 != 1)
        printf("%s  %d %%   ",lesReponsesBis[26],rng3);
 	if(barrage3 != 1 || D5050 != 1)
        printf("%s  %d %%   \n\n\n",lesReponsesBis[27],rng4);
        }
        break;
    case 7:
        if(Dpublic == 0)
        {

 	if(barrage1 != 1 || D5050 != 1)
        printf("%s    ",lesReponsesBis[28]);
 	if(barrage2 != 1 || D5050 != 1)
        printf("%s     \n",lesReponsesBis[29]);
 	if(barrage3 != 1 || D5050 != 1)
        printf("%s     ",lesReponsesBis[30]);
        printf("%s     \n\n\n",lesReponsesBis[31]);

        }
        else if(Dpublic == 1)
        {
                if(temoinRNG == 1)
             RNG();

 	if(barrage1 != 1 || D5050 != 1)
        printf("%s  %d %%  ",lesReponsesBis[28],rng1);
 	if(barrage2 != 1 || D5050 != 1)
        printf("%s  %d %%   \n",lesReponsesBis[29],rng2);
 	if(barrage3 != 1 || D5050 != 1)
        printf("%s  %d %%   ",lesReponsesBis[30],rng3);
        printf("%s  %d %%   \n\n\n",lesReponsesBis[31],rng4);
        }
        break;
    case 8:
        if(Dpublic == 0)
        {

 	if(barrage1 != 1 || D5050 != 1)
        printf("%s    ",lesReponsesBis[32]);
 	if(barrage2 != 1 || D5050 != 1)
        printf("%s     \n",lesReponsesBis[33]);
        printf("%s     ",lesReponsesBis[34]);
 	if(barrage3 != 1 || D5050 != 1)
        printf("%s     \n\n\n",lesReponsesBis[35]);

        }
        else if(Dpublic == 1)
        {
                if(temoinRNG == 1)
            RNG();

 	if(barrage1 != 1 || D5050 != 1)
        printf("%s  %d %%  ",lesReponsesBis[32],rng1);
 	if(barrage2 != 1 || D5050 != 1)
        printf("%s  %d %%   \n",lesReponsesBis[33],rng2);
        printf("%s  %d %%   ",lesReponsesBis[34],rng3);
 	if(barrage3 != 1 || D5050 != 1)
        printf("%s  %d %%  \n\n\n",lesReponsesBis[35],rng4);
        }
        break;
    case 9:
        if(Dpublic == 0)
        {

 	if(barrage1 != 1 || D5050 != 1)
        printf("%s    ",lesReponsesBis[36]);
 	if(barrage2 != 1 || D5050 != 1)
        printf("%s     \n",lesReponsesBis[37]);
 	if(barrage3 != 1 || D5050 != 1)
        printf("%s     ",lesReponsesBis[38]);
        printf("%s    \n\n\n",lesReponsesBis[39]);

        }
        else if(Dpublic == 1)
        {
                if(temoinRNG == 1)
             RNG();

 	if(barrage1 != 1 || D5050 != 1)
        printf("%s  %d %%  ",lesReponsesBis[36],rng1);
 	if(barrage2 != 1 || D5050 != 1)
        printf("%s  %d %%  \n",lesReponsesBis[37],rng2);
 	if(barrage3 != 1 || D5050 != 1)
        printf("%s  %d %%   ",lesReponsesBis[38],rng3);
        printf("%s  %d %%   \n\n\n",lesReponsesBis[39],rng4);
        }
        break;
    case 10:
        if(Dpublic == 0)
        {

        printf("%s    ",lesReponsesBis[40]);
 	if(barrage1 != 1 || D5050 != 1)
        printf("%s     \n",lesReponsesBis[41]);
 	if(barrage2 != 1 || D5050 != 1)
        printf("%s     ",lesReponsesBis[42]);
 	if(barrage3 != 1 || D5050 != 1)
        printf("%s     \n\n\n",lesReponsesBis[43]);

        }
        else if(Dpublic == 1)
        {
                if(temoinRNG == 1)
             RNG();

        printf("%s  %d %%  ",lesReponsesBis[40],rng1);
 	if(barrage1 != 1 || D5050 != 1)
        printf("%s  %d %%   \n",lesReponsesBis[41],rng2);
 	if(barrage2 != 1 || D5050 != 1)
        printf("%s  %d %%  ",lesReponsesBis[42],rng3);
 	if(barrage3 != 1 || D5050 != 1)
        printf("%s  %d %%   \n\n\n",lesReponsesBis[43],rng4);
        }
        break;
    case 11:
        if(Dpublic == 0)
        {

 	if(barrage1 != 1 || D5050 != 1)
        printf("%s    ",lesReponsesBis[44]);
 	if(barrage2 != 1 || D5050 != 1)
        printf("%s     \n",lesReponsesBis[45]);
 	if(barrage3 != 1 || D5050 != 1)
        printf("%s     ",lesReponsesBis[46]);
        printf("%s     \n\n\n",lesReponsesBis[47]);

        }
        else if(Dpublic == 1)
        {
            if(temoinRNG == 1)
             RNG();

 	if(barrage1 != 1 || D5050 != 1)
        printf("%s  %d %%   ",lesReponsesBis[44],rng1);
 	if(barrage2 != 1 || D5050 != 1)
        printf("%s  %d %%   \n",lesReponsesBis[45],rng2);
 	if(barrage3 != 1 || D5050 != 1)
        printf("%s  %d %%   ",lesReponsesBis[46],rng3);
        printf("%s  %d %%   \n\n\n",lesReponsesBis[47],rng4);
        }
        break;

    default: printf("ya un pb (ReponsePossibleAffiche.Bis");break;
        }
    }

void LaBonneReponse(char lbr)
{
        if(inputReponse== lbr)
        {
            BonneReponse();
        }
        else
        {
            FausseReponse();
        }
}
void Verification()
{
    switch(numeroQuestion)
    {
    case 0: LaBonneReponse('A');break; //check
    case 1: LaBonneReponse('C');break; //check
    case 2: LaBonneReponse('B');break; //check
    case 3: LaBonneReponse('C');break; //check
    case 4: LaBonneReponse('D');break; //check
    case 5: LaBonneReponse('C');break; //check
    case 6: LaBonneReponse('D');break; //check
    case 7: LaBonneReponse('A');break; //check
    case 8: LaBonneReponse('A');break; //check
    case 9: LaBonneReponse('A');break; //check
    case 10: LaBonneReponse('C');break;//check
    case 11: LaBonneReponse('D');break;//check

    default: printf("ya un pb (Verification");break;
    }
}
void VerificationBis()
{
    switch(numeroQuestion)
    {
    case 0: LaBonneReponse('B');break;//check
    case 1: LaBonneReponse('A');break;//check
    case 2: LaBonneReponse('B');break;//check
    case 3: LaBonneReponse('C');break;//check
    case 4: LaBonneReponse('D');break;//check
    case 5: LaBonneReponse('C');break;//check
    case 6: LaBonneReponse('B');break;//check
    case 7: LaBonneReponse('D');break;//check
    case 8: LaBonneReponse('C');break;//check
    case 9: LaBonneReponse('A');break;//check
    case 10: LaBonneReponse('D');break;//check
    case 11: LaBonneReponse('B');break;//check

    default: printf("ya un pb (VerificationBis");break;
    }
}
void Inputer()
{
    if(Jswitch == 1 || J5050== 1 || JPublic == 1)
    {
            printf("Vous souhaiter repondre? Ou d'abord utiliser un bonus? Vous ne pouvez pas retourner en arrière.(Repondez par R ou B) vous pouver abandonner en tapant E et repartir avec vos gain actuel\n");
        do
        {
            RepOuBonus = getchar();
        }while (RepOuBonus != 'R' && RepOuBonus!='B'&& RepOuBonus != 'E');

    }

    if(RepOuBonus == 'B')
    {
        do
        {

            printf("Choisisser un bonus ( Taper S pour switch, P pour public et M pour 50/50) vous pouvez en jouer autant que vous le vouler\n Sinon taper R pour sortir et repondre.");
            inputBonus = getchar();
            fflush(stdin);
            Bonus();
            system("cls");
            Afficheur();




        }while( inputBonus!='R');
    }

    if(RepOuBonus== 'R' || inputBonus == 'R')
    {

        do
        {
            printf("Taper votre réponse (A, B, C ou D\n");
            fflush(stdin);
            inputReponse = getchar();
        }while(inputReponse != 'A'&& inputReponse != 'B' && inputReponse != 'C' && inputReponse != 'D');

    }
    if(RepOuBonus == 'E')
    {
       abandon = 1;
    }

}


void Progression(int gainNumero)
{
    if(gainNumero == 12)
    {
        printf("\n\n                    | 1000000 |\n");
    }
    else
    {
        printf("                    1000000\n");
    }
    if(gainNumero == 11)
    {
        printf("                    | 500000 |\n");
    }
    else
    {
        printf("                    500000\n");
    }
    if(gainNumero == 10)
    {
        printf("                    | 200000 |\n");
    }
    else
    {
        printf("                    200000\n");
    }
    if(gainNumero == 9)
    {
        printf("                    | 20000 |\n");
    }
    else
    {
        printf("                    20000\n");
    }
    if(gainNumero == 8)
    {
        printf("                    | 10000 |\n");
    }
    else
    {
        printf("                    10000\n");
    }
    if(gainNumero == 7)
    {
        printf("                    | 5000 |\n");
    }
    else
    {
        printf("                    5000\n");
    }
    if(gainNumero == 6)
    {
        printf("                    | 3000 |\n");
    }
    else
    {
        printf("                    3000\n");
    }
    if(gainNumero == 5)
    {
        printf("                    | 2000 |\n");
    }
    else
    {
        printf("                    2000\n");
    }
    if(gainNumero == 4)
    {
        printf("                    | 1000 |\n");
    }
    else
    {
        printf("                    1000\n");
    }
    if(gainNumero == 3)
    {
        printf("                    | 500 |\n");
    }
    else
    {
        printf("                    500\n");
    }
    if(gainNumero == 2)
    {
        printf("                    | 200 |\n");
    }
    else
    {
        printf("                    200\n");
    }
    if(gainNumero == 1)
    {
        printf("                    | 100 |\n");
    }
    else
    {
        printf("                    100\n");
    }

}
void BonusAffiche()
{
    if(Jswitch == 1)
    {

        printf("| Switch |");

    }
    else
    {
        printf("|        |");

    }
    if(J5050 == 1)
    {
        printf("| 50/50 |");
    }
    else
    {
        printf("|        |\n");
    }
    if(JPublic == 1)
    {

        printf("| Public |\n");

    }
    else
    {

        printf("|        |\n");

    }

}

void Afficheur()
{

    BonusAffiche();
    printf("\n\n\n");

    if(DSwitch == 0)
    {

    Question(numeroQuestion);
    ReponsePossibleAffiche();
    }
    else
    {
        QuestionBis(numeroQuestion);
        ReponsePossibleAfficheBis();
    }

    Progression(prixNumero);

}
void ResultatFinal()
{

    if(echouer == 1)
    {
        printf("Vous avez echouer, vous reparter avec rien\n");
    }
    else if (abandon == 1)
    {
        printf("Vous reparter avec %d\n",gain[prixNumero-1]);
    }
    else if((gain[prixNumero] > 0 && gain[prixNumero] < 1000000))
    {
        printf("Vous reparter avec %d\n",gain[prixNumero]);
    }
    else if(prixNumero == 12)
    {
        printf("Felicitation vous reparter avec la somme maximal\n");
    }
    printf("Voulez vous rejouer? entrer un charactère quelconque pour jouer, sinon taper n minuscule");
    //scanf(" %c",&rejouer);
    rejouer = getch();
}

int main()
{
    srand(time(NULL));
   do
   {
    VariableRetourneAZero();
    system("cls");
    printf("Bienvenu dans qui veux gagner un million, %ctes vous pret a commencer?\nTaper entrée pour continuer.",136);
    fflush(stdin);
    getch();
    printf("Pour jouer, vous devez taper R pour ensuite entrée une des quatre lettres A B C D EN MAJUSCULE et valider avec entrer,\n Vous pouvr utiliser les joker en tapant d'abord B, puis S pour switch, M pour 50/50 et P pour public.\nTaper entrée pour continuer");
    fflush(stdin);
    getch();
    system("cls");
     do
     {
        Afficheur();
        Inputer();
        if(DSwitch == 0 && RepOuBonus != 'E')
            Verification();
        else if (RepOuBonus != 'E')
        {

            VerificationBis();
        }
        numeroQuestion++;
        system("cls");
        inputBonus = '0';
        inputReponse = '0';
        RepOuBonus = '0';
        DSwitch = 0;
        Dpublic = 0;
        D5050 = 0;
     }while(echouer !=1 && numeroQuestion != 12 && abandon != 1 );
     ResultatFinal();
   }while(rejouer !='n');

    return 0;
}
