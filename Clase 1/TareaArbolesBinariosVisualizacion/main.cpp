#include <fstream>
#include <iostream>
#include <deque>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
#include "Utilidades.h"
using namespace std;

struct BinaryTree {
  BinaryTree *left, *right;
  int data;
  BinaryTree(int val) : left(NULL), right(NULL), data(val) { }
};

// Indica la altura máxima del árbol binario.
int maxHeight(BinaryTree *p) {
  if (!p) return 0;
  int leftHeight = maxHeight(p->left);
  int rightHeight = maxHeight(p->right);
  return (leftHeight > rightHeight) ? leftHeight + 1: rightHeight + 1;
}

// Convertir un valor entero en una cadena
string intToString(int val) {
  ostringstream ss;
  ss << val;
  return ss.str();
}

// Imprime las ramas del brazo (p. Ej., / \) En una línea
void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<BinaryTree*>& nodesQueue, ostream& out) {
  deque<BinaryTree*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel / 2; i++) {
    out << ((i == 0) ? setw(startLen-1) : setw(nodeSpaceLen-2)) << "" << ((*iter++) ? "/" : " ");
    out << setw(2*branchLen+2) << "" << ((*iter++) ? "\\" : " ");
  }
  out << endl;
}

// Imprima las ramas y el nodo (por ejemplo, ___10___)
void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<BinaryTree*>& nodesQueue, ostream& out) {
  deque<BinaryTree*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->left) ? setfill('_') : setfill(' '));
    out << setw(branchLen+2) << ((*iter) ? intToString((*iter)->data) : "");
    out << ((*iter && (*iter)->right) ? setfill('_') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
  }
  out << endl;
}

// Imprima solo las hojas (solo para la fila inferior)
void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<BinaryTree*>& nodesQueue, ostream& out) {
  deque<BinaryTree*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << ((*iter) ? intToString((*iter)->data) : "");
  }
  out << endl;
}

// Formato de un árbol binario para el flujo de salida
// @ param
// level Control, el ancho que desea que tenga el árbol (por ejemplo, el nivel 1 tiene el espacio mínimo entre los nodos, mientras que el nivel 2 tiene un espacio más grande entre los nodos)
// indentSpace. Cambie esto para agregar un espacio de sangría a la izquierda (por ejemplo, indentSpace de 0 significa que el nivel más bajo del nodo izquierdo se mantendrá en el margen izquierdo)
void printPretty(BinaryTree *root, int level, int indentSpace, ostream& out) {
  int h = maxHeight(root);
  int nodesInThisLevel = 1;

  int branchLen = 2*((int)pow(2.0,h)-1) - (3-level)*(int)pow(2.0,h-1);  // eq de la longitud de la rama para cada nodo de cada nivel
  int nodeSpaceLen = 2 + (level+1)*(int)pow(2.0,h);  // distancia entre el brazo derecho del nodo vecino izquierdo y el brazo izquierdo del nodo vecino derecho
  int startLen = branchLen + (3-level) + indentSpace;  // espacio inicial al primer nodo para imprimir de cada nivel (solo para el nodo más a la izquierda de cada nivel)

  deque<BinaryTree*> nodesQueue;
  nodesQueue.push_back(root);
  for (int r = 1; r < h; r++) {
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
    branchLen = branchLen/2 - 1;
    nodeSpaceLen = nodeSpaceLen/2 + 1;
    startLen = branchLen + (3-level) + indentSpace;
    printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);

    for (int i = 0; i < nodesInThisLevel; i++) {
      BinaryTree *currNode = nodesQueue.front();
      nodesQueue.pop_front();
      if (currNode) {
          nodesQueue.push_back(currNode->left);
          nodesQueue.push_back(currNode->right);
      } else {
        nodesQueue.push_back(NULL);
        nodesQueue.push_back(NULL);
      }
    }
    nodesInThisLevel *= 2;
  }
  printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
  printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, out);
}

int main() {
	SetConsoleTitleA("Arboles binarios-visualizacion - Tarea UFG"); //Cambiar el titulo de la consola
	
	
	//Instanciando clases
	Utilidades _Utilidad;
		
	 _Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tESTUDIANTE (AUTOR): CASTILLO ARTIAGA, JOSE ALFREDO", true); // Color CYAN
	_Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tCARNE: CA102817", true); // Color CYAN
	
  BinaryTree *root = new BinaryTree(1);
  root->left = new BinaryTree(2);
  root->right = new BinaryTree(3);
  root->left->left = new BinaryTree(4);
  root->left->left->right = new BinaryTree(17);
  root->left->left->left = new BinaryTree(18);
  root->left->left->left->left = new BinaryTree(51);
  root->left->left->left->right = new BinaryTree(52);
  root->left->right = new BinaryTree(2);
  root->right->left = new BinaryTree(20);
  root->right->left->left = new BinaryTree(21);
  root->right->left->right = new BinaryTree(22);
  root->right->right = new BinaryTree(10);
  root->left->right->left = new BinaryTree(27);
  root->left->right->right = new BinaryTree(28);
  root->right->right->left = new BinaryTree(41);
  root->right->right->right = new BinaryTree(42);
  root->right->right->right->left = new BinaryTree(60);
  root->right->right->right->right = new BinaryTree(61);  


  string _NombreArchivo = "ImpresionArbol.txt";
  cout << "\tImpresion de arbol con multiples niveles \n";
  // Salida a consola
  printPretty(root, 1, 0, cout);

  cout << "\n\tGenerando txt con diseno del arbol. En proceso...\n";
  // Crea un archivo y da salida a ese archivo
  ofstream _fileArbol(_NombreArchivo);
  // Ahora imprima un árbol que esté más extendido en el archivo.
  printPretty(root, 5, 0, _fileArbol);
  
  _fileArbol.close();
  
  //Validamos si el archivo ha sido creado y luego lo abrimos en visualizacion maxima, usanod el comando: start/max ImpresionArbol.txt
	fstream _file(_NombreArchivo);
	if (!_file.is_open()) {	//Valida si existe el txt
		_Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_RED, "\tEl archivo no ha sido creado!", true);
	}
	else {
		_Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, "\tEl archivo fue creado!. Se ha almacenado en la raiz del sistema", true);
		_file.close(); //Cerramos el sftream
		
		cout << "\n\tAbriendo archivo...\n\n";
		
		string _comando = "start/max " + _NombreArchivo; //Crear comando para abri el txt
		system(_comando.c_str()); //Ejecutar comando para abril el txt
	}

  return 0;
}
