#include <limits>

#include "BoundingBoxCalculator.h"
#include "Objet3DPart.h"

BoundingBoxCalculator::BoundingBoxCalculator(void)
{
	// initialiser les bornes minimum aux plus grandes valeurs possibles
	// le float maximum est: std::numeric_limits<float>::max();

	// initialiser les bornes maximum aux plus petites valeurs possibles
	// le float minimum est: std::numeric_limits<float>::min();
	m_boite[0] = std::numeric_limits<float>::max(); //xmin
	m_boite[2] = std::numeric_limits<float>::max(); //ymin
	m_boite[4] = std::numeric_limits<float>::max(); //zmin
	m_boite[1] = std::numeric_limits<float>::min(); //xmax
	m_boite[3] = std::numeric_limits<float>::min(); //ymax
	m_boite[5] = std::numeric_limits<float>::min(); //zmax
}

void BoundingBoxCalculator::visit(Objet3DPart & obj)
{
	// Iterer sur tous les triangles contenus dans l'objet et faire:
	//    - Comparer les coordonnees des sommets des triangles aux bornes actuelle de la boite
	//    - Si une coordonnee est plus petite qu'une coordonnee min, faire:
	//         - stoker la nouvelle coordonnee min
	//    - Si une coordonnee est plus grande qu'une coordonnee max, faire:
	//         - stoker la nouvelle coordonnee max

	TriangleIterator it = obj.triangle_begin();
	while (it != obj.triangle_end()) {	
				if (it->s1().x < m_boite[0])
					m_boite[0] = it->s1().x;
				else if (it->s2().x < m_boite[0])
					m_boite[0] = it->s1().x;
				
		it++;
	}
}
