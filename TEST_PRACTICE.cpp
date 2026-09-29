#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;
void ordenarSeleccion(int[], string[], float[], int);
int main(){
	const int MAX_ESTUDIANTES = 100;
    int ids[MAX_ESTUDIANTES];
    string nombres[MAX_ESTUDIANTES];
    float notas[MAX_ESTUDIANTES];
    int totalEstudiantes = 0;
	ifstream arch_leido("C:\\Users\\PC\\Downloads\\estudiantes.txt");
	
	if(arch_leido.fail()){
		cout << "El archivo no existe.\nError";
		exit(1);
	}else{
		cout << "Archivo Abierto con exito\n";
	}
	string line;
	while(getline(arch_leido, line) && totalEstudiantes < MAX_ESTUDIANTES){
		if(line.empty()){
			continue;
		}
		int coma1 = line.find(',');
		int coma2 = line.find(',', coma1 + 1);
		cout << line << endl << coma1 << endl << coma2 << endl;
		if (coma1 != string::npos && coma2 != string::npos) {
            string codigoStr = line.substr(0, coma1);
            string nombreStr = line.substr(coma1 + 1, coma2 - coma1 - 1);
            string notaStr = line.substr(coma2 + 1);

			string idDigitos = "";
            for (char c : codigoStr) {
                if (isdigit(c)) { // Verificación con isdigit
                    idDigitos += c;
                }
			}
    int id = atoi(idDigitos.c_str());    // Cadena a entero
    float nota = atof(notaStr.c_str());  // Cadena a flotante

			ids[totalEstudiantes] = id;
            nombres[totalEstudiantes] = nombreStr;
            notas[totalEstudiantes] = nota;
            totalEstudiantes++;
        }
	}
    arch_leido.close();
	ordenarSeleccion(ids, nombres, notas, totalEstudiantes);
ofstream archivoSalida("reporte_ordenado.txt");

    if (archivoSalida.fail()) {
        cerr << "Error: No se pudo crear el archivo reporte_ordenado.txt" << endl;
        return 1;
    }

    archivoSalida << "=== REPORTE DE ESTUDIANTES ORDENADOS ===" << endl;
    for (int i = 0; i < totalEstudiantes; i++) {
        archivoSalida << "ID: " << ids[i]
                      << " | Nombre: " << nombres[i]
                      << " | Nota: " << notas[i] << endl;
    }
    archivoSalida.close(); // Cierre del flujo de salida
    cout << "Proceso completado con exito. Revisa 'reporte_ordenado.txt'." << endl;
    return 0;
}

void ordenarSeleccion(int ids[], string nombres[], float notas[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (notas[j] > notas[maxIdx]) {
                maxIdx = j;
            }
        }
        
        // Intercambio en los 3 arreglos para mantener la sincronía
        if (maxIdx != i) {
            float auxNota = notas[i];
            notas[i] = notas[maxIdx];
            notas[maxIdx] = auxNota;

            int auxId = ids[i];
            ids[i] = ids[maxIdx];
            ids[maxIdx] = auxId;

            string auxNombre = nombres[i];
            nombres[i] = nombres[maxIdx];
            nombres[maxIdx] = auxNombre;
        }
    }
}