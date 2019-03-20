#ifndef GALOIS_FIELD_H
#define GALOIS_FIELD_H

// Fixed at GF(2^8)
class GaloisField {
public:
	GaloisField();
	~GaloisField();
	// Return 0 on error
	unsigned char GetElement(int elementNum) const;
	unsigned char Add(unsigned char num, unsigned char addNum) const;
	unsigned char Minus(unsigned char num, unsigned char minusNum) const;
	unsigned char Multiply(unsigned char num, unsigned char multiplyNum) const;
	unsigned char Divide(unsigned char num, unsigned char divideNum) const;
private:
	int _fieldSize;
	int _polynomial;
	int _numElements;
	unsigned char *_pLogTable;
	unsigned char *_pExponentialTable;
};
#endif /* GALOIS_FIELD_H */
