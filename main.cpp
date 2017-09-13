#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<cmath>

// Declaração de variáveis
int FIGURE = 0;
float RED = 0.0f, GREEN = 0.0f, BLUE = 0.0f;

// Função callback de redesenho da janela de visualização
void Desenha(void)
{
	printf("*** Callback de redesenho da tela\n");

	// Define a cor de fundo de tela
	glClearColor(RED, GREEN, BLUE, 1.0f);
	// Limpa a janela de visualização com a cor de fundo definida
	glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);

	if(FIGURE == 1){
     // Desenha um triângulo no centro da janela
	 glBegin(GL_TRIANGLES);
	    glVertex3f(-0.5,-0.5,0);
	 	glVertex3f( 0.0, 0.5,0);
	 	glVertex3f( 0.5,-0.5,0);
	 glEnd();
    } else if(FIGURE == 2){
     // Desenha um quadrado no centro da janela
	 glBegin(GL_QUADS);
	   	glVertex3f(-0.5,-0.5,0);
	 	glVertex3f(-0.5,0.5,0);
	 	glVertex3f( 0.5, 0.5,0);
	 	glVertex3f( 0.5,-0.5,0);
	 glEnd();

    } else if(FIGURE == 3){
     // Desenha um polígono no centro da janela
     glBegin(GL_POLYGON);
       	glVertex3f(-0.20,-0.35,0);
	 	glVertex3f(-0.35,0.05,0);
	 	glVertex3f( 0.0, 0.35,0);
	 	glVertex3f( 0.35,0.05,0);
	 	glVertex3f( 0.20,-0.35,0);
	 glEnd();

    } else if(FIGURE == 4){
     // Desenha um polígono no centro da janela
     glBegin(GL_TRIANGLE_STRIP);
       	glVertex3f(-0.5,-0.5,0);
	 	glVertex3f( 0.0, 0.5,0);
	 	glVertex3f( 0.5,-0.5,0);
	 glEnd();
    }


	// Exibe o desenho na janela
	glutSwapBuffers();
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	printf("*** Callback de redimensionamento da tela\n");
	printf(">>> Novo tamanho da janela: %d x %d \n\n", w, h);
}

// Função callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char tecla, int x, int y)
{
	int modificadores;
	printf("*** Tratamento de teclas comuns\n");
	printf(">>> Tecla: %c\n",tecla);

	if (tecla == 27)
		exit(0);

	if (tecla == 'a') // muda para tela cheia
		glutFullScreen();
	if (tecla == 'A') // muda posição da janela
	{
		glutReshapeWindow(500,400);
		glutPositionWindow(100,100);
	}

	// Trata SHIFT, CTRL e ALT
	modificadores = glutGetModifiers();
	if (modificadores & GLUT_ACTIVE_SHIFT)
		printf("(SHIFT pressionado)\n");
	if (modificadores & GLUT_ACTIVE_CTRL)
		printf("(CTRL pressionado)\n");
	if (modificadores & GLUT_ACTIVE_ALT)
		printf("(ALT pressionado)\n");
}

// Função callback chamada para gerenciar eventos de teclas especiais(F1,PgDn,...)
void TeclasEspeciais (int tecla, int x, int y){
	printf("*** Tratamento de teclas especiais\n");
	switch (tecla){
		case GLUT_KEY_F1:
         printf(">>> Tecla F1 pressionada\n");
         break;
		case GLUT_KEY_F2:
         printf(">>> Tecla F2 pressionada\n");
		 break;
		case GLUT_KEY_F3:
         printf(">>> Tecla F3 pressionada\n");
		 break;
	}
}

// Função que trata a opção selecionada do menu principal
void MenuPrincipal(int op){
	printf("*** Menu principal!\n");
}

// Função callback chamada quando são notificados os eventos do mouse
void GerenciaMouse (int button, int state, int x, int y)
{
	printf("*** Tratamento de Cliques de mouse\n");
	if (state == GLUT_DOWN)
		printf(">>> Botao %d pressionado\n",button);
	if (state == GLUT_UP)
		printf(">>> Botao %d liberado\n",button);
}

// Função que trata a opção selecionada do menu "Primitiva"
void MenuPrimitiva(int op)
{
	printf("*** Menu PRIMITIVA: ");
	switch(op) {
		case 0:
            FIGURE = 1;
			printf("Opcao TRIANGULO");
			break;
		case 1:
            FIGURE = 2;
			printf("Opcao QUADRADO");
			break;
		case 2:
            FIGURE = 3;
			printf("Opcao POLÍGONO");
			break;

        case 3:
            FIGURE = 4;
            printf("Opcao ESTRELA");
            break;
	}
	printf("\n");
	glutPostRedisplay();
}

// Função que trata a opção selecionada do menu "Cor"
void MenuCor(int op)
{
	printf("*** Menu COR: ");
	switch(op) {
		case 0:
			printf("Opcao PRETO");
			RED = 0.0f; GREEN = 0.0f; BLUE = 0.0f;
			break;
		case 1:
			printf("Opcao BRANCO");
			RED = 1.0f; GREEN = 1.0f; BLUE = 1.0f;
			break;
		case 2:
			printf("Opcao AZUL");
     		RED = 0.0f; GREEN = 0.0f; BLUE = 1.0f;
			break;
	}
	printf("\n");
	glutPostRedisplay();
}

// Função responsável por criar os menus
void CriaMenu()
{
	int menu,submenu1,submenu2;

	// Cria submenu para seleção de cor
	submenu1 = glutCreateMenu(MenuCor);
	glutAddMenuEntry("Preto",0);
	glutAddMenuEntry("Branco",1);
	glutAddMenuEntry("Azul",2);

	// Cria submenu para seleção de primitiva
	submenu2 = glutCreateMenu(MenuPrimitiva);
	glutAddMenuEntry("Triangulo",0);
	glutAddMenuEntry("Quadrado",1);
	glutAddMenuEntry("Poligono",2);

	// Cria menu principal...
	menu = glutCreateMenu(MenuPrincipal);
	// ... e adiciona ambos submenus a ele
	glutAddSubMenu("Cor",submenu1);
	glutAddSubMenu("Primitivas",submenu2);

	// Associa o menu ao botão direito do mouse
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void myinit(){
   //Chama função para criar o menu
   CriaMenu();
   // defini onde esta sendo visualizado
   //gluOrtho2D(-1.0, 3.0, -1.0, 3.0);

}
// Programa Principal
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
	// Define do modo de operação da GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB );

	// Especifica a posição inicial da janela GLUT
	glutInitWindowPosition(0,0);

	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(500,400);

	// Cria a janela passando como argumento o título da mesma
	glutCreateWindow("Programa de Teste da GLUT");

	// Registra a função callback de redesenho da janela de visualização
	glutDisplayFunc (Desenha);

	// Registra a função callback de redimensionamento da janela de visualização
	glutReshapeFunc (AlteraTamanhoJanela);

	// Registra a função callback para tratamento das teclas ASCII
	glutKeyboardFunc (Teclado);

	// Registra a função callback que gerencia os eventos do mouse
	glutMouseFunc (GerenciaMouse);

	// Registra a função callback para tratamento das teclas especiais
	glutSpecialFunc (TeclasEspeciais);

	// Chama função de inicialização
    myinit();

	// Inicia o processamento e aguarda interações do usuário
	glutMainLoop();

	return 0;
}
