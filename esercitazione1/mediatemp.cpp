#include <iostream> 
#include <fstream>
#include <string>

int main(int argc, const char *argv[]) {
	
	//Verifica che siano stati passati almeno due argomenti al programma
	if (argc<2)
	{
		std::cerr<<"File da processare non specificato"<<std::endl;
		return 1;
	}
	
	//Apro file ricevuto (situato in argv[]) e lo chiamo file_input
	std::ifstream file_input(argv[1]);
	
	std::string citta;
	double t1, t2, t3, t4, tmedia;
	
	//se il file è aperto, eseguo l'algoritmo, altrimenti restituisco un errore
	if (file_input.is_open())
	{
		while (file_input >> citta >> t1 >> t2 >> t3 >> t4)
		{
			tmedia = (t1+t2+t3+t4)/4.0;
			std::cout<< citta << ": " << tmedia << std::endl;
		}
		file_input.close();
		return 0;
	}
	else
	{
		std::cerr<<"Impossibile aprire il file"<<std::endl;
		return 1;
	}
}

//utilizzo IA: l'intelligenza artificiale generativa è stata utilizzata per chiarire alcuni dubbi di forma (in particolare sulla sintassi corretta da utilizzare in alcuni punti del codice). Il codice è interamente scritto a mano. 