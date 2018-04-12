#include "OutputVisitor.h"
#include "Objet3DPart.h"
#include "Objet3DComposite.h"
#include "Objet3DTransform.h"

void OutputVisitor::visit(Objet3DPart & obj)
{
	// Imprimer tous les triangles contenus dans l'objet
	// Chaque triangle est imprime selon le format
	// "T#: (x, y, z) | (x, y, z) | (x, y, z)"
	// ou: # est le numero du triangle a partir de 0
	//     (x, y, z) sont les coordonnees d'un sommet
	auto iter = obj.triangle_begin();
	int compteur = 0;
	for (iter; iter != obj.triangle_end(); iter++) {

		Sommet s1 = iter->s1();
		Sommet s2 = iter->s2();
		Sommet s3 = iter->s3();

		m_stream << m_indent << "T" << compteur << ": "
			<< "(" << s1.x() << ", " << s1.y() << ", " << s1.z() << ")" << "|"
			<< "(" << s2.x() << ", " << s2.y() << ", " << s2.z() << ")" << "|"
			<< "(" << s3.x() << ", " << s3.y() << ", " << s3.z() << ")" << std::endl;

		compteur++;
	}

}

void OutputVisitor::visit(Objet3DComposite & obj)
{
	// Imprimer tous les enfants de l'objet
	// Si le composite a des enfants faire:
	//    - incrementer le niveau d'indentation de 3 espaces
	//    - invoquer le visiteur sur chaque enfant
	//    - decrementer le niveau d'indentation
	
	auto iter = obj.begin();
	m_stream << m_indent << "COMPOSITE" << std::endl;
	m_indent += "   ";
	for (iter; iter != obj.end(); iter++) {

		iter->accueillir(*this);
	}
	m_indent = m_indent.substr(0, m_indent.length() - 3);

}

void OutputVisitor::visit(Objet3DTransform & obj)
{
	// Imprimer les attributs de la transformation selon le format:
	// "TRANSFO [dx, dy, dz]"
	// ou : dx, dy et dz sont les composantes de la transformation		
	float x = obj.dx();
	float y = obj.dy();
	float z = obj.dz();
	m_stream << m_indent << "TRANSFO [" << x << ", " << y << ", " << z << "]" << std::endl;
}


