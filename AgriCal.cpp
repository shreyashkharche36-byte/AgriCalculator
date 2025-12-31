#include <iostream>
#include <string>
#include <algorithm> // For transforming text to lowercase
#include <iomanip>   // For setting decimal precision

using namespace std;

// Function to convert string to lowercase for comparison
string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    // 1. Setup Environment
    // In C++, we don't need clc/clear, but we set output formatting
    cout << fixed << setprecision(2);

    cout << "===================================================" << endl;
    cout << "      Agricultural Fertilizer Dosage Calculator      " << endl;
    cout << "===================================================" << endl;

    string unit_area = "hectares (ha)";
    string unit_mass = "kilograms (kg)";

    // 2. Get User Input
    string crop_input;
    double land_size;

    cout << "Enter the crop type (e.g., Corn, Wheat, Rice): ";
    getline(cin, crop_input);
    
    // Normalize input to lowercase
    string crop = toLowerCase(crop_input);

    // Get land size with validation
    while (true) {
        cout << "Enter the land size in " << unit_area << " (e.g., 5.5): ";
        if (cin >> land_size && land_size > 0) {
            break;
        } else {
            cout << "Invalid input. Please enter a positive number for land size." << endl;
            cin.clear(); // Clear error flags
            cin.ignore(10000, '\n'); // Discard bad input
        }
    }

    // 3. Determine NPK Rates
    double N_rate = 0;
    double P_rate = 0;
    double K_rate = 0;

    // C++ Switch statements only work with integers, so we use if-else for strings
    if (crop == "corn" || crop == "maize") {
        N_rate = 150;
        P_rate = 70;
        K_rate = 50;
        cout << "Selected Crop: Corn (Maize)" << endl;
    } else if (crop == "wheat") {
        N_rate = 120;
        P_rate = 60;
        K_rate = 40;
        cout << "Selected Crop: Wheat" << endl;
    } else if (crop == "rice") {
        N_rate = 100;
        P_rate = 50;
        K_rate = 30;
        cout << "Selected Crop: Rice" << endl;
    } else {
        cout << " " << endl;
        cout << "[Warning] No specific data found for crop: " << crop_input << endl;
        cout << "Using default base rate (N: 50, P: 25, K: 25 kg/ha)." << endl;
        N_rate = 50;
        P_rate = 25;
        K_rate = 25;
    }

    // 4. Calculate Total Dose
    double total_N = N_rate * land_size;
    double total_P = P_rate * land_size;
    double total_K = K_rate * land_size;
    double total_NPK = total_N + total_P + total_K;

    // 5. Display Results
    cout << "===================================================" << endl;
    cout << "Summary for " << land_size << " " << unit_area << " of " << crop_input << endl;
    cout << "===================================================" << endl;

    cout << "Recommended Nutrient Dose (Pure Nutrient Mass):" << endl;
    cout << "  Nitrogen (N)       : " << total_N << " " << unit_mass << endl;
    cout << "  Phosphate (P2O5)   : " << total_P << " " << unit_mass << endl;
    cout << "  Potash (K2O)       : " << total_K << " " << unit_mass << endl;
    
    cout << "\nTotal Estimated NPK Mass Required: " << total_NPK << " " << unit_mass << endl;
    
    cout << endl;
    cout << "*** IMPORTANT: The amounts above are pure nutrient mass." << endl;
    cout << "    Actual application will require commercial fertilizers." << endl;
    cout << "===================================================" << endl;

    return 0;
}