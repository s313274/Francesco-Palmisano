#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

#include "sort.hpp"
#include "randfiller.h"
#include "timecounter.h"

int main()
{
    randfiller rf;
    timecounter tc;     
    int num_vettori = 100;

    // Intestazione aggiornata con la colonna "Ibrido" e "std::sort"
    std::cout << "Dim\tBubble\t\tSelect\t\tInsert\t\tMerge\t\tQuick\t\tIbrido\t\tstd::sort\n";
    std::cout << "------------------------------------------------------------------------------------------------------------------------------\n";

    // Ciclo sulle dimensioni: da 5 a 100 elementi
    for (int dim = 5; dim <= 100; dim += 5)
    {
        // 1. Preallochiamo i 100 vettori base e li riempiamo
        std::vector<std::vector<int>> vettori_base(num_vettori, std::vector<int>(dim));
        for (int i = 0; i < num_vettori; i++)
        {
            rf.fill(vettori_base[i], -1000, 1000);
        }

        std::cout << dim << "\t";

        // --- TEST BUBBLESORT ---
        auto vettori_test = vettori_base; 
        tc.tic();
        for (int i = 0; i < num_vettori; i++) {
            bubble_sort(vettori_test[i]);
        }
        std::cout << tc.toc() / num_vettori << "\t";

        // --- TEST SELECTIONSORT ---
        vettori_test = vettori_base; 
        tc.tic();
        for (int i = 0; i < num_vettori; i++) {
            selection_sort(vettori_test[i]);
        }
        std::cout << tc.toc() / num_vettori << "\t";

        // --- TEST INSERTIONSORT ---
        vettori_test = vettori_base; 
        tc.tic();
        for (int i = 0; i < num_vettori; i++) {
            insertion_sort(vettori_test[i]);
        }
        std::cout << tc.toc() / num_vettori << "\t";

        // --- TEST MERGESORT ---
        vettori_test = vettori_base; 
        tc.tic();
        for (int i = 0; i < num_vettori; i++) {
            mergesort(vettori_test[i], 0, dim - 1);
        }
        std::cout << tc.toc() / num_vettori << "\t";

        // --- TEST QUICKSORT ---
        vettori_test = vettori_base; 
        tc.tic();
        for (int i = 0; i < num_vettori; i++) {
            quicksort(vettori_test[i], 0, dim - 1);
        }
        std::cout << tc.toc() / num_vettori << "\t"; 

        // --- TEST QUICKSORT IBRIDO ---
        vettori_test = vettori_base; 
        tc.tic();
        for (int i = 0; i < num_vettori; i++) {
            quick_insertion_sort(vettori_test[i], 0, dim - 1);
        }
        std::cout << tc.toc() / num_vettori << "\t"; 

        // --- TEST STD::SORT (Libreria Standard) ---
        vettori_test = vettori_base; 
        tc.tic();
        for (int i = 0; i < num_vettori; i++) {
            std::sort(vettori_test[i].begin(), vettori_test[i].end());
        }
        std::cout << tc.toc() / num_vettori << "\n"; // Fine riga
    }

    return 0;
}

// Questo algoritmo è stato sviluppato con il sostegno di IA, in particolare per l'impaginazione degli output in tabella