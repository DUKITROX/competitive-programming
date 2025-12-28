//---------------------------------------------------------
// Problema 611 Conan Doyle y Sean Connery
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
#include <map>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool casoDePrueba() {

    if(!cin){
        return false;
    }else{
        int ano_sir, n_casos;
        string nombre, primera_obra_sir;
        cin >> ano_sir;
        if(cin.fail()){
            return false;
        }else{
            cin.ignore();
            getline(cin, nombre);
            cin >> n_casos;
        
            map<int, string> obras;
        
            //Leer obras y escribirlas en un hashmap
            int ano_obra;
            string titulo_obra;
            
            for(int i = 0; i < n_casos; i++){      
                cin >> ano_obra;
                cin.ignore();
                getline(cin, titulo_obra);
                obras[ano_obra] = titulo_obra;
            }

            //Crear puntero
            map<int,string>::iterator iter;
            //array de solo los años de las obras
            vector<int> anos_obras;
    
            bool todas_obra_sir = true, ninguna_obra_sir = true;
            for(iter = obras.begin(); iter != obras.end(); iter++){
                //cout << "CLAVE: " << iter->first << " VALOR: " << iter->second << endl;
                if(iter->first >= ano_sir){
                    anos_obras.push_back(iter->first);
                    ninguna_obra_sir = false;
                }else{
                    todas_obra_sir = false;
                }
            }
            
            if(todas_obra_sir){
                cout << "TODAS" << endl;
            }else if(ninguna_obra_sir){
                cout << "NINGUNA" << endl;
            }else{
                int ano_primera_obra_sir = anos_obras[0];
                for(int i = 0; i < anos_obras.size(); i++){
                    if(anos_obras[i] <= ano_primera_obra_sir){
                        ano_primera_obra_sir = anos_obras[i];
                    }
                }
                cout << obras[ano_primera_obra_sir] << endl;
            }
        }
    return true;
    }
}

//---------------------------------------------------------
int main(){
	while (casoDePrueba()) {
	}
	return 0;
}