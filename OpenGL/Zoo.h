class Animal { /* Some virtual members */ };
class Dog : public Animal {};
class Cat : public Animal {};
#include <vector>
void main() {
	Dog     dog;
	Cat     cat;
	Animal& AnimalRef1 = dog;  // Notice no cast required. (Dogs and cats are animals).
	Animal& AnimalRef2 = cat;
	Animal* AnimalPtr1 = &dog;
	Animal* AnimalPtr2 = &cat;

	Cat&    catRef1 = dynamic_cast<Cat&>(AnimalRef1);  // Throws an exception  AnimalRef1 is a dog
	Cat*    catPtr1 = dynamic_cast<Cat*>(AnimalPtr1);  // Returns NULL         AnimalPtr1 is a dog
	Cat&    catRef2 = dynamic_cast<Cat&>(AnimalRef2);  // Works
	Cat*    catPtr2 = dynamic_cast<Cat*>(AnimalPtr2);  // Works

													   // This on the other hand makes no sense
													   // An animal object is not a cat. Therefore it can not be treated like a Cat.
	Animal  a;
	Cat&    catRef1 = dynamic_cast<Cat&>(a);    // Throws an exception  Its not a CAT
	Cat*    catPtr1 = dynamic_cast<Cat*>(&a);   // Returns NULL         Its not a CAT.

	std::vector<Animal*>  barnYard;
	barnYard.push_back(&dog);
	barnYard.push_back(&cat);

	Dog*  dog = dynamic_cast<Dog*>(barnYard[1]); // Note: NULL as this was the cat.
}