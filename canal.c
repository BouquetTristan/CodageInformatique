#include "canal.h"

//int code[tailleHadamar];

/*void creerCode(int code[tailleHadamard])
{
  int leCode;
  printf("Entrer le code hadamar : ");
  for (size_t i = 0; i < tailleHadamard; i++)
  {
    scanf("%i", &leCode);
    code[i] = leCode;
  }
}
*/
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

int codage (int code[], int tailleHadamard)
{
  //creerCode(code);

  int tailleMsg, msg, modulo;


  printf("Entrer la taille de votre message (le nombre de caractère) : ");
  scanf("%i", &tailleMsg);
  printf("Entrer votre message (que des 1 ou des 0) : ");
  scanf("%i", &msg);

  int tabMsg[tailleMsg];
  int tailleMsgCode = tailleMsg*tailleHadamard;
  int tabMsgCode[tailleMsgCode];

  //printf("  Modulo : %i\n", modulo);
  //printf("  Message : %i\n", msg);

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

      //afficherTab(tabMsg, tailleMsg);
    }
  }
  else
  {
    for (size_t i = 0; i < tailleMsg; i++)
    {
      modulo = puiss(tailleMsg-i, 10);
      if(msg < modulo)
        tabMsg[i] = 0;
      else
      {
        tabMsg[i] = 1;
        msg -= modulo;
      }
    }
  }



  for (size_t i = 0; i < tailleMsg; i++)
  {
    for (size_t j = 0; j < tailleHadamard; j++)
    {
      //printf("%i ", tabMsg[i]);
      if(tabMsg[i] == 1)
        tabMsgCode[j+i*tailleHadamard] = code[j];
      else
        tabMsgCode[j+i*tailleHadamard] = -code[j];
    }
  }
  printf("Message codé : ");
  afficherTab(tabMsgCode, tailleMsgCode);

}
