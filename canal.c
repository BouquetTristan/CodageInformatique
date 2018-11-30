#include "canal.h"

int code[H3];

void creerCode(int code[H3])
{
  int leCode;

  for (size_t i = 0; i < H3; i++)
  {
    scanf("%i", &leCode);
    code[i] = leCode;
  }
}

void encoderMsg(int canal, int msg)
{

}
int puiss(int nbRecurence, int puissance)
{
  if(nbRecurence == 1)
    return 1;
  else
    return (puissance*puiss(nbRecurence-1, puissance));
}

void afficherTab(int tab[], int limite)
{
  printf("[");
  for (size_t i = 0; i < limite; i++)
  {
    printf(" %i", tab[i]);
    if(i < limite-1)
    {
      printf(",");
    }
  }
  printf("]\n");
}

int verifMsg(int msg, int tailleMsg)
{
  tailleMsg = puiss(tailleMsg, 10);
  //printf("%i\n", tailleMsg);

  if( msg > tailleMsg)
    return 1;
  else
    return 0;
}

int main ()
{
  creerCode(code);

  int tailleMsg, msg, modulo;


  printf("Entrer la taille de votre message (le nombre de caractère) : ");
  scanf("%i", &tailleMsg);
  printf("Entrer votre message (que des 1 ou des 0) : ");
  scanf("%i", &msg);

  int tabMsg[tailleMsg];
  int tailleMsgCode = tailleMsg*H3;
  int tabMsgCode[tailleMsgCode];

  if(!verifMsg(msg, tailleMsg))
  {
    //printf("Valeur du message : %i\n", msg);
    tabMsg[0] = 0;
    for (size_t i = 0; i < tailleMsg; i++)
    {
      modulo = puiss(tailleMsg-i, 8);
      if(msg < modulo)
        tabMsg[i] = 0;
      else
      {
        tabMsg[i] = 1;
        msg -= modulo;
      }

      //printf("     Modulo : %i\n", modulo);
      //afficherTab(tabMsg, tailleMsg);
    }
  }



  for (size_t i = 0; i < tailleMsg; i++)
  {
    for (size_t j = 0; j < H3; j++)
    {
      if(tabMsg[i] == 1)
        tabMsgCode[j+i*H3] = code[j];
      else
        tabMsgCode[j+i*H3] = -code[j];
    }
  }
  afficherTab(tabMsgCode, tailleMsgCode);

}
