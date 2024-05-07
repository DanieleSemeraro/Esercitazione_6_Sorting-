#include <sstream>
#include <vector>
#include "SortingAlgorithm.hpp"
#include <gtest/gtest.h>
#include <chrono>
#include <thread>
using namespace std;

void testbubblesort() {
    // Simula un lavoro che richiede tempo, ad esempio:
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::vector<int> int_vs = { 4, 6, 3, 5, 2, 1 };

    SortLibrary::BubbleSort(int_vs);
    print(int_vs);
    SortLibrary::MergeSort(int_vs);
    print(int_vs);

    std::vector<std::string> str_vs = {
        "delta", "foxtrot", "charlie",
        "echo", "bravo", "alpha"
    };

    SortLibrary::BubbleSort(str_vs);
    print(str_vs);
    SortLibrary::MergeSort(str_vs);
    print(str_vs);

}
void testmergesort() {
    // Simula un lavoro che richiede tempo, ad esempio:
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::vector<int> int_vs = { 4, 6, 3, 5, 2, 1 };

    SortLibrary::MergeSort(int_vs);
    print(int_vs);

    std::vector<std::string> str_vs = {
        "delta", "foxtrot", "charlie",
        "echo", "bravo", "alpha"
    };

    SortLibrary::MergeSort(str_vs);
    print(str_vs);

}
TEST(MyTestSuite, PerformanceTest) {
    auto start = std::chrono::high_resolution_clock::now();

    // Chiamata alla funzione che vogliamo testare
    testbubblesort();//DEBUG:987.4+1008.82+1006.27+990.628+994.596+1010.94
    //RELEASE:1005.98+1003.46+988.774+1001.21+1011.55
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed1 = end1 - start;

    std::cout << "Tempo trascorso: " << elapsed1.count() << " millisecondi" << std::endl;
    auto start2 = std::chrono::high_resolution_clock::now();
    testmergesort();//DEBUG:1010.76+1011.97+1010.64+1012.18+1014.38+1012.59
    //RELEASE:1013.7+1013.9+1011.96+1013.19+1011.7
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed2 = end2 - start2;

    std::cout << "Tempo trascorso: " << elapsed2.count() << " millisecondi" << std::endl;

    // Asserzione opzionale: verifica che il tempo di esecuzione sia sotto una certa soglia
    //ASSERT_LT(elapsed2.count(), 2100); // Assicurati che il tempo trascorso sia minore di 1500 millisecondi
}


int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}

