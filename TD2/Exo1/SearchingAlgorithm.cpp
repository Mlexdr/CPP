#include "SearchingAlgorithm.h"
int SearchingAlgorithm::totalComparison=0;
int SearchingAlgorithm::totalSearch=0;
double SearchingAlgorithm::averageComparison=0;

SearchingAlgorithm::SearchingAlgorithm():numberComparisons(0)
{
}
void SearchingAlgorithm::displaySearchResults(std::ostream& os, int res, int target){
    totalComparison += numberComparisons;
    totalSearch++;
    if (totalSearch > 0){
        averageComparison = totalComparison/totalSearch;
    }
    if(res != -1){
        os << "Élement trouvé à l'indice :" << res << "\n";
    }else{
        os << "Élément non trouvé\n";
    }
    os << "Comparaisons pour cette recherche:"<<numberComparisons<<"\n";
    os << "Total des comparaisons:"<<totalComparison<<"\n";
    os << "Total des recherches:"<<totalSearch<<"\n";
    os << "Moyenne des comparaisons:"<<averageComparison<<"\n\n";
}