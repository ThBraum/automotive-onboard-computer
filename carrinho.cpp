#include <iostream>
#include <ctime>
#include <sys/time.h>
#include <windows.h>
#include <locale.h>
#include <chrono>
#include <bits/stdc++.h>

auto start = std::chrono::high_resolution_clock::now();

using namespace std;

/*
UNICAMP POO - EP5
Autores: Matheus Thomaz Braum RA: 185358
         João Victor Dourado Barbosa RA: 216823

    Ligar; Desligar; Velocidade; Parar veiculo Distancia percorrida; Consumo combustivel; Temp do oléo de transm.; Voltagem bateria; Pressão oléo; Temp motor; rpm motor; data; sair
     1         2          3           4                 5                      6                       7                  8                 9            10          11      12    0
*/

class Veiculo{
    bool ligado = false;
    bool parado = true;
    double velocidade = 0.0;
    double distancia = 0.0;
    double recebe_distancia = 0.0;

    public:
    bool ligar_veiculo();
    bool desligar_veiculo();
    void velocidade_veiculo();
    bool parar_veiculo();
    double distancia_veiculo();
    void consumo_veiculo();
    /*void n_rotacoes_motor();
    void temp_motor();
    void press_oleo();
    void voltagem_bateria();
    void temp_oleo_transmiss();
    void dataehora();
    void consumo_medio_combust();
    void dist_percorrida();*/


};

void dataehora();

bool Veiculo::ligar_veiculo(){
    system("cls");
    if(ligado == true){
        cout << "O veículo já está ligado";
    }else{
        cout << "O veiculo foi ligado";
    }

    cout << "\n\n\nRetornando ao MENU...";
    Sleep(2500);
    return ligado = true;
    }

bool Veiculo::desligar_veiculo(){
    system("cls");
    if(ligado == false){
        cout << "O veículo já está desligado";
    }else{
        cout << "O veiculo foi desligado";
    }

    cout << "\n\n\nRetornando ao MENU...";
    velocidade = 0.0;
    Sleep(2500);
    return ligado = false;
    }


void Veiculo:: velocidade_veiculo(){
    char ch;
    char ch2;
    system("cls");
    if(ligado == true){
        if(parado == true){
            cout << "Veículo parado. Deseja movimentá-lo? (S/N)";
            cin >> ch;
            if(ch == 's' or ch == 'S'){
                velocidade = 20.0;
                do{

                    parado = false;

                    int c_start = clock();
                    start = std::chrono::high_resolution_clock::now(); //inicializa o clock

                    system("cls");
                    cout << "Velocidade atual: " << velocidade << " KM/H                                                Velocidade máxima: 200 KM/H";

                    cout << "\n\nDeseja acelerar? (S/N)";
                    cin >> ch2;
                    if(ch2 == 's' or ch2 == 'S'){
                        if(velocidade < 200){
                            velocidade = velocidade + 20.0;
                        }else{
                            cout << "\nVelocidade máxima atingida. Desaja desacelerar? (S/N)";
                            cin >> ch2;
                            if(ch2 == 's' or ch2 == 'S'){
                                velocidade = velocidade - 20.0;
                            }else{
                                break;
                            }
                        }
                    }else{
                        cout << "Deseja desacelerar? (S/N)";
                        cin >> ch2;
                        if(ch2 == 's' or ch2 == 'S'){
                            velocidade = velocidade - 20.0;
                        }else{
                            system("cls");
                            cout << "Velocidade atual: " << velocidade;

                            cout << "\n\n\nPressione ENTER para continuar.";
                            std::cin.sync(); std::cin.get();
                        }
                    }
                }while(ch2 == 's' or ch2 == 'S');
            }
        }else{
            do{
                    parado = false;
                    system("cls");
                    cout << "Velocidade atual: " << velocidade << " KM/H                                                Velocidade máxima: 200 KM/H";

                    cout << "\n\nDeseja acelerar? (S/N)";
                    cin >> ch2;
                    if(ch2 == 's' or ch2 == 'S'){
                        if(velocidade < 200){
                            velocidade = velocidade + 20.0;
                        }else{
                            cout << "\nVocê já atingiu a velocidade máxima! Ao invés disso deseja desacelerar? (S/N)";
                            cin >> ch2;
                            if(ch2 == 's' or ch2 == 'S'){
                                velocidade = velocidade - 20.0;
                            }else{
                                break;
                            }
                        }
                    }else{
                        cout << "Deseja desacelerar? (S/N)";
                        cin >> ch2;
                        if(ch2 == 's' or ch2 == 'S'){
                            velocidade = velocidade - 30.0;
                        }else{
                            system("cls");
                            cout << "Velocidade atual: " << velocidade;

                            cout << "\n\n\nPressione ENTER para continuar.";
                            std::cin.sync(); std::cin.get();
                        }
                    }
                }while(ch2 == 's' or ch2 == 'S');
        }
    }else{
        cout << "O veículo se encontra desligado. Para iniciar o movimento ligue o carro primeiro.";

        cout << "\n\n\nRetornando ao MENU...";
        Sleep(3000);
    }
}

bool Veiculo:: parar_veiculo(){
    system("cls");
    if(parado == true){
        cout << "O veículo já está parado!";
    }else{
        cout << "Parando o veículo...";
        velocidade = 0.0;
    }

    cout << "\n\n\nRetornando ao MENU...";
    Sleep(2500);
    return parado = true;
}

double Veiculo:: distancia_veiculo(){
    system("cls");
    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = finish - start;

    //std::cout << "Elapsed time: " << elapsed.count() << " s\n";

    if(velocidade != 0){
        double velocidadems = velocidade / 3.6;
        double distancia = velocidadems * elapsed.count();
        recebe_distancia = recebe_distancia + distancia;

        cout << "Velocidade atual: " << velocidade << " KM/H                                                Velocidade M/S: " << velocidadems;
        cout << "\nTempo decorrido: " << elapsed.count() << " seg.";

        cout.precision(3);
        cout << "\nDistancia percorrida: " << recebe_distancia / 1000 << " Km";

        cout << "\n\n\nPressione ENTER para continuar.";
        std::cin.sync(); std::cin.get();

        return recebe_distancia;
    }else{
        cout << "\nDistancia percorrida: " << recebe_distancia / 1000 << " Km";

        cout << "\n\n\nPressione ENTER para continuar.";
        std::cin.sync(); std::cin.get();
    }
}

void Veiculo:: consumo_veiculo(){
    system("cls");
    double consumo = recebe_distancia / 10000;

    cout << "Média de consumo: 10Km/L" << endl;
    cout.precision(3);
    cout << "\nGasolina consumida: " << consumo << " L";
    cout << "\n\n\nPressione ENTER para continuar.";
    std::cin.sync(); std::cin.get();
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    Veiculo veiculo;
    int opc;


    do{


        system("cls");
		cout<<"\n\n\n\t MENU";
		cout<<"\n\n\t[ 01 ] LIGAR VEICULO" << endl;
		cout<<"\t[ 02 ] DESLIGAR VEICULO" << endl;
		cout<<"\t[ 03 ] VELOCIDADE DO VEICULO" << endl;
		cout<<"\t[ 04 ] PARAR VEICULO" << endl;
		cout<<"\t[ 05 ] DISTANCIA PERCORRIDA" << endl;
		cout<<"\t[ 06 ] CONSUMO DE COMBUSTIVEL" << endl;
		cout<<"\t[ 07 ] TEMP. ÓLEO DE TRANSM." << endl;
		cout<<"\t[ 08 ] VOLTAGEM DA BATERIA" << endl;
		cout<<"\t[ 09 ] PRESSÃO DO ÓLEO" << endl;
		cout<<"\t[ 10 ] TEMP. MOTOR" << endl;
		cout<<"\t[ 11 ] RPM MOTOR" << endl;
		cout<<"\t[ 12 ] DATA E HORA" << endl;
		cout<<"\t[ 00 ] SAIR" << endl;
		cout<<"\n\tOpcao: ";
		cin >> opc;

        switch (opc){
            case 1:
            veiculo.ligar_veiculo();
            break;
        case 2:
            veiculo.desligar_veiculo();
            break;
        case 3:
            veiculo.velocidade_veiculo();
            break;
        case 4:
            veiculo.parar_veiculo();
            break;
        case 5:
            veiculo.distancia_veiculo();
            break;
        case 6:
            veiculo.consumo_veiculo();
            break;
        case 12:
            dataehora();
            break;
        case 0:
            system("cls");
            cout << "BI BI. TCHAU";
            break;
        default:
            cout << "Ta funcionando ñ";
            break;
        }
    }while(opc != 0);


    return 0;
}

void dataehora(){
    system("cls");
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();


    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << std::ctime(&end_time);


    cout << "\n\n\nPressione ENTER para continuar.";
    std::cin.sync(); std::cin.get();

    //Sleep(2500);

}
