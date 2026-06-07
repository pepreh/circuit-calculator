#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    double voltage, current, resistance, power;
    int choice;
    
    cout << "===== CIRCUIT CALCULATOR (OHM'S LAW) =====" << endl;
    
    while (true) {
        cout << "\n--- What do you want to calculate? ---" << endl;
        cout << "1. Calculate Resistance (V = I × R)" << endl;
        cout << "2. Calculate Current (I = V ÷ R)" << endl;
        cout << "3. Calculate Voltage (V = I × R)" << endl;
        cout << "4. Calculate Power (P = V × I)" << endl;
        cout << "5. Save Calculation to File" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose option: ";
        cin >> choice;
        
        if (choice == 1) {
            cout << "\nEnter Voltage (V): ";
            cin >> voltage;
            cout << "Enter Current (A): ";
            cin >> current;
            
            if (current == 0) {
                cout << "Error: Current cannot be zero!" << endl;
                continue;
            }
            
            resistance = voltage / current;
            cout << fixed << setprecision(2);
            cout << "\nResistance = " << resistance << " Ω (Ohms)" << endl;
        }
        
        else if (choice == 2) {
            cout << "\nEnter Voltage (V): ";
            cin >> voltage;
            cout << "Enter Resistance (Ω): ";
            cin >> resistance;
            
            if (resistance == 0) {
                cout << "Error: Resistance cannot be zero!" << endl;
                continue;
            }
            
            current = voltage / resistance;
            cout << fixed << setprecision(2);
            cout << "\nCurrent = " << current << " A (Amperes)" << endl;
        }
        
        else if (choice == 3) {
            cout << "\nEnter Current (A): ";
            cin >> current;
            cout << "Enter Resistance (Ω): ";
            cin >> resistance;
            
            voltage = current * resistance;
            cout << fixed << setprecision(2);
            cout << "\nVoltage = " << voltage << " V (Volts)" << endl;
        }
        
        else if (choice == 4) {
            cout << "\nEnter Voltage (V): ";
            cin >> voltage;
            cout << "Enter Current (A): ";
            cin >> current;
            
            power = voltage * current;
            cout << fixed << setprecision(2);
            cout << "\nPower = " << power << " W (Watts)" << endl;
        }
        
        else if (choice == 5) {
            ofstream file("circuit_calculations.txt", ios::app);
            file << "\n===== CIRCUIT CALCULATION =====\n";
            file << "Voltage: " << voltage << " V\n";
            file << "Current: " << current << " A\n";
            file << "Resistance: " << resistance << " Ω\n";
            file << "Power: " << power << " W\n";
            file.close();
            cout << "\nCalculation saved to 'circuit_calculations.txt'" << endl;
        }
        
        else if (choice == 6) {
            cout << "Goodbye!" << endl;
            break;
        }
        
        else {
            cout << "Invalid option. Try again." << endl;
        }
    }
    
    return 0;
}
