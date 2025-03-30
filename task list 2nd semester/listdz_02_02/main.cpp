#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;

class Polynomial {
private:
    vector<double> coefficients; // Vector of coefficients (a0, a1, a2, ...)
    vector<int> exponents;      // Vector of exponents (0, 1, 2, ...)
    int degree;                 // Degree of the polynomial

public:
    // Constructors
    Polynomial() : degree(-1) {} // Default constructor creates empty polynomial
    
    Polynomial(int deg) : degree(deg) {
        if (deg < 0) {
            throw invalid_argument("Degree must be non-negative");
        }
        coefficients.resize(deg + 1, 0.0);
        exponents.resize(deg + 1);
        for (int i = 0; i <= deg; ++i) {
            exponents[i] = i;
        }
    }
    
    Polynomial(const vector<double>& coeffs) {
        degree = coeffs.size() - 1;
        coefficients = coeffs;
        exponents.resize(coeffs.size());
        for (size_t i = 0; i < coeffs.size(); ++i) {
            exponents[i] = i;
        }
    }
    
    Polynomial(const Polynomial& other) : 
        coefficients(other.coefficients), 
        exponents(other.exponents), 
        degree(other.degree) {}
    
    // Destructor
    ~Polynomial() = default;
    
    // Getters
    int getDegree() const { return degree; }
    vector<double> getCoefficients() const { return coefficients; }
    vector<int> getExponents() const { return exponents; }
    
    // Setters
    void setCoefficient(int index, double value) {
        if (index < 0 || index > degree) {
            throw out_of_range("Index out of bounds");
        }
        coefficients[index] = value;
    }
    
    void setDegree(int newDegree) {
        if (newDegree < degree) {
            throw invalid_argument("New degree cannot be less than current degree");
        }
        coefficients.resize(newDegree + 1, 0.0);
        exponents.resize(newDegree + 1);
        for (int i = degree + 1; i <= newDegree; ++i) {
            exponents[i] = i;
        }
        degree = newDegree;
    }
    
    // Print polynomial
    void print() const {
        if (degree == -1) {
            cout << "0";
            return;
        }
        
        for (int i = 0; i <= degree; ++i) {
            if (i > 0 && coefficients[i] >= 0) {
                cout << " + ";
            } else if (coefficients[i] < 0) {
                cout << " - ";
            }
            
            if (i == 0) {
                cout << coefficients[i];
            } else {
                cout << abs(coefficients[i]) << "x";
                if (exponents[i] > 1) {
                    cout << "^" << exponents[i];
                }
            }
        }
        cout << endl;
    }
    
    // Evaluate polynomial for given x
    double evaluate(double x) const {
        double result = 0.0;
        for (int i = 0; i <= degree; ++i) {
            result += coefficients[i] * pow(x, exponents[i]);
        }
        return result;
    }
    
    // Polynomial addition
    Polynomial operator+(const Polynomial& other) const {
        int maxDegree = max(degree, other.degree);
        Polynomial result(maxDegree);
        
        for (int i = 0; i <= maxDegree; ++i) {
            double coeff1 = (i <= degree) ? coefficients[i] : 0.0;
            double coeff2 = (i <= other.degree) ? other.coefficients[i] : 0.0;
            result.setCoefficient(i, coeff1 + coeff2);
        }
        
        return result;
    }
    
    // Polynomial subtraction
    Polynomial operator-(const Polynomial& other) const {
        int maxDegree = max(degree, other.degree);
        Polynomial result(maxDegree);
        
        for (int i = 0; i <= maxDegree; ++i) {
            double coeff1 = (i <= degree) ? coefficients[i] : 0.0;
            double coeff2 = (i <= other.degree) ? other.coefficients[i] : 0.0;
            result.setCoefficient(i, coeff1 - coeff2);
        }
        
        return result;
    }
};

class VectPolynomial {
private:
    vector<Polynomial> polynomials;
    
public:
    // Constructors
    VectPolynomial() = default;
    VectPolynomial(const vector<Polynomial>& polys) : polynomials(polys) {}
    VectPolynomial(const VectPolynomial& other) : polynomials(other.polynomials) {}
    
    // Destructor
    ~VectPolynomial() = default;
    
    // Getters
    vector<Polynomial> getPolynomials() const { return polynomials; }
    size_t getCount() const { return polynomials.size(); }
    
    // Setters
    void addPolynomial(const Polynomial& poly) {
        polynomials.push_back(poly);
    }
    
    void setPolynomial(size_t index, const Polynomial& poly) {
        if (index >= polynomials.size()) {
            throw out_of_range("Index out of bounds");
        }
        polynomials[index] = poly;
    }
    
    // Print all polynomials
    void print() const {
        for (size_t i = 0; i < polynomials.size(); ++i) {
            cout << "Polynomial " << i + 1 << ": ";
            polynomials[i].print();
        }
    }
    
    // Process polynomials as described in the task
    static VectPolynomial processPolynomials(const VectPolynomial& v1, const VectPolynomial& v2) {
        if (v1.getCount() != v2.getCount()) {
            throw invalid_argument("Vectors must be of the same size");
        }
        
        VectPolynomial result;
        size_t count = v1.getCount();
        
        for (size_t i = 0; i < count; ++i) {
            if (i % 2 == 0) { // Even index (0-based)
                // Odd V1 with even V2 (since 0 is even, 1 is odd, etc.)
                Polynomial sum = v1.polynomials[i] + v2.polynomials[i];
                result.addPolynomial(sum);
            } else { // Odd index
                // Even V1 with odd V2
                Polynomial diff = v1.polynomials[i] - v2.polynomials[i];
                result.addPolynomial(diff);
            }
        }
        
        return result;
    }
};

// Global function to get count of polynomials in a vector
size_t getPolynomialCount(const VectPolynomial& vp) {
    return vp.getCount();
}

int main() {
    try {
        // Create two vectors of polynomials V1 and V2
        VectPolynomial v1, v2;
        
        // Fill V1 with polynomials of degrees 0 to 5
        for (int i = 0; i < 6; ++i) {
            Polynomial p(i);
            for (int j = 0; j <= i; ++j) {
                p.setCoefficient(j, (j + 1) * 1.5); // Sample coefficients
            }
            v1.addPolynomial(p);
        }
        
        // Fill V2 with different polynomials of degrees 0 to 5
        for (int i = 0; i < 6; ++i) {
            Polynomial p(i);
            for (int j = 0; j <= i; ++j) {
                p.setCoefficient(j, (j + 1) * 2.0); // Different coefficients
            }
            v2.addPolynomial(p);
        }
        
        cout << "Vector V1 contains " << getPolynomialCount(v1) << " polynomials:" << endl;
        v1.print();
        cout << endl;
        
        cout << "Vector V2 contains " << getPolynomialCount(v2) << " polynomials:" << endl;
        v2.print();
        cout << endl;
        
        // Process the polynomials as per the requirement
        VectPolynomial vResult = VectPolynomial::processPolynomials(v1, v2);
        
        cout << "Resulting vector VResult after processing:" << endl;
        vResult.print();
        cout << endl;
        
        // Evaluate polynomials with x = 2.0
        double x = 2.0;
        cout << "Evaluating polynomials at x = " << x << ":" << endl;
        for (size_t i = 0; i < vResult.getCount(); ++i) {
            cout << "Polynomial " << i + 1 << " value: " 
                 << vResult.getPolynomials()[i].evaluate(x) << endl;
        }
        
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}