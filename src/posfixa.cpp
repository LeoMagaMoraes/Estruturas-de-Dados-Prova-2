#include "../include/posfixa.hpp"
#include <stdexcept>
#include <cctype>  

int posfixa(Fila<char> &entrada) {
Pilha<int> Pilha;

char token = entrada.desenfileirar();  

        if (std::isdigit(token)) {
            Pilha.empilhar(token - '0');  
        }
        
        else if (token == '+' || token == '-' || token == '*' || token == '/') {
            if (Pilha.esta_vazia()) {
                throw std::runtime_error("operando faltando.");
            }
            int b = Pilha.desempilhar();  
            if (Pilha.esta_vazia()) {
                throw std::runtime_error("operando faltando.");
            }
            int a = Pilha.desempilhar();  

            int resultado;
            switch (token) {
                case '+': 
                resultado = a + b; 
                break;
                case '-': 
                resultado = a - b; 
                break;
                case '*': 
                resultado = a * b; 
                break;
                case '/': 
                    if (b == 0) {
                        throw std::runtime_error("Erro: divisão por zero.");
                    }
                    resultado = a / b; 
                    break;
                default:
                    throw std::runtime_error("Operador inválido.");
            }
            Pilha.empilhar(resultado);  
        } 
        else {
            throw std::runtime_error(" caractere inválido.");
        }

    if (Pilha.esta_vazia()) {
        throw std::runtime_error("resultado faltando.");
    }

    return Pilha.desempilhar(); 
}
