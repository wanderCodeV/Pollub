//Mariia Nyzhnyk grupa 1.4.8

#include "my_vector.h"
#include "unreal.h"
#include <vector>
#include <memory>

int main()
{

    std::vector<UMeshComponent*> meshes;
    meshes.emplace_back(new USkinnedMeshComponent);
    meshes.emplace_back(new USkeletalMeshComponent);
    meshes.emplace_back(new UStaticMeshComponent);
    meshes.emplace_back(new UWidgetComponent);

    for (auto& mesh : meshes)
    {
        mesh->Render();
    }
    std::cout << "\n\n";

    vector4<double> v4(1, 2, 3, 4);
    std::cout << "Dlugosc wektora v4 wynosi\n";
    std::cout << v4.length() << std::endl;

    std::unique_ptr<vector4<float>> pv4(std::make_unique<vector4 < float>>( 1, 1, 1, 1 ));
    std::cout << "Dlugosc wektora v = (1, 1, 1, 1) wynosi\n";
    std::cout << pv4->length() << std::endl;

    system("PAUSE");

    return 0;
}

