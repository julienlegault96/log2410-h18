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
	unsigned int indice = 0;
	TriangleIterator it = obj.triangle_begin();
	while (it != obj.triangle_end()) {
		m_stream << m_indent
		<< "T" << indice++ << ":"
		<< "(" << it->s1() << ")" << "|"
		<< "(" << it->s2() << ")" << "|"
		<< "(" << it->s3() << ")" << std::endl;
		it++;
	}

}

void OutputVisitor::visit(Objet3DComposite & obj)
{
	// Imprimer tous les enfants de l'objet
	// Si le composite a des enfants faire:
	//    - incrementer le niveau d'indentation de 3 espaces
	//    - invoquer le visiteur sur chaque enfant
	//    - decrementer le niveau d'indentation
	
	m_indent += "   ";
	Objet3DIterator it = obj.begin();	
	while (it != obj.end()) {
		it->accueillir(*this);
		it++;
	}
	m_indent = m_indent.substr(3, m_indent.size());

}

void OutputVisitor::visit(Objet3DTransform & obj)
{
	// Imprimer les attributs de la transformation selon le format:
	// "TRANSFO [dx, dy, dz]"
	// ou : dx, dy et dz sont les composantes de la transformation		
		m_stream << m_indent
		<< "TRANSFO" << "["
		<< obj.dx << ","
		<< obj.dy << ","
		<< obj.dz << "]"			
		<< std::endl;	
}


