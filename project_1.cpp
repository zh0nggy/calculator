#include <iostream>
#include <cmath>

int main() {
    // Final examination
    double F_max{ 0.0 };
    while ( (F_max <= 0.0) || (F_max != std::round( F_max )) ) 
    {std::cout << "Enter the maximum grade on the final examination: ";
        std::cin >> F_max;
    }

    double F{ -1.0 };
    while ( (F < 0.0) || (F > F_max) ) {
        std::cout << "Enter your grade on the final examination: ";
        std::cin >> F;
    }

    // Mid-term examination
    double M_max{ 0.0 };
    while ( (M_max <= 0.0) || (M_max != std::round( M_max )) ) {
        std::cout << "Enter the maximum grade on the mid-term examination: ";
        std::cin >> M_max;
    }

    double M{ -1.0 };
    while ( (M < 0.0) || (M > M_max) ) {
        std::cout << "Enter your grade on the mid-term examination: ";
        std::cin >> M;
    }

    // Project 1
    double P1_max{ 0.0 };
    while ( (P1_max <= 0.0) || (P1_max != std::round( P1_max )) ) {
        std::cout << "Enter the maximum grade on project 1: ";
        std::cin >> P1_max;
    }

    double P1{ -1.0 };
    while ( (P1 < 0.0) || (P1 > P1_max) ) {
        std::cout << "Enter your grade on project 1: ";
        std::cin >> P1;
    }

    // Project 2
    double P2_max{ 0.0 };
    while ( (P2_max <= 0.0) || (P2_max != std::round( P2_max )) ) {
        std::cout << "Enter the maximum grade on project 2: ";
        std::cin >> P2_max;
    }

    double P2{ -1.0 };
    while ( (P2 < 0.0) || (P2 > P2_max) ) {
        std::cout << "Enter your grade on project 2: ";
        std::cin >> P2;
    }

    // Project 3
    double P3_max{ 0.0 };
    while ( (P3_max <= 0.0) || (P3_max != std::round( P3_max )) ) {
        std::cout << "Enter the maximum grade on project 3: ";
        std::cin >> P3_max;
    }

    double P3{ -1.0 };
    while ( (P3 < 0.0) || (P3 > P3_max) ) {
        std::cout << "Enter your grade on project 3: ";
        std::cin >> P3;
    }

    // Project 4
    double P4_max{ 0.0 };
    while ( (P4_max <= 0.0) || (P4_max != std::round( P4_max )) ) {
        std::cout << "Enter the maximum grade on project 4: ";
        std::cin >> P4_max;
    }

    double P4{ -1.0 };
    while ( (P4 < 0.0) || (P4 > P4_max) ) {
        std::cout << "Enter your grade on project 4: ";
        std::cin >> P4;
    }

    // Project 5
    double P5_max{ 0.0 };
    while ( (P5_max <= 0.0) || (P5_max != std::round( P5_max )) ) {
        std::cout << "Enter the maximum grade on project 5: ";
        std::cin >> P5_max;
    }

    double P5{ -1.0 };
    while ( (P5 < 0.0) || (P5 > P5_max) ) {
        std::cout << "Enter your grade on project 5: ";
        std::cin >> P5;
    }

    // Convert every grade to be out of 100
    double F_100{ 100.0*F/F_max };
    double M_100{ 100.0*M/M_max };
    double P1_100{ 100.0*P1/P1_max };
    double P2_100{ 100.0*P2/P2_max };
    double P3_100{ 100.0*P3/P3_max };
    double P4_100{ 100.0*P4/P4_max };
    double P5_100{ 100.0*P5/P5_max };

    // Supremacy of the final examination
    if ( M_100 < F_100 ) {
        M_100 = F_100;
    }

    if ( P1_100 < F_100 ) {
        P1_100 = F_100;
    }

    if ( P2_100 < F_100 ) {
        P2_100 = F_100;
    }

    if ( P3_100 < F_100 ) {
        P3_100 = F_100;
    }

    if ( P4_100 < F_100 ) {
        P4_100 = F_100;
    }

    if ( P5_100 < F_100 ) {
        P5_100 = F_100;
    }

    // Examination weighted average and project average
    double E_100{ 0.75*F_100 + 0.25*M_100 };
    double P_100{ (P1_100 + P2_100 + P3_100 + P4_100 + P5_100)/5.0 };

    // Final grade calculation
    double final_grade{ 0.0 };

    if ( E_100 <= 40.0 ) {
        final_grade = E_100;
    } else if ( E_100 >= 60.0 ) {
        final_grade = (2.0/3.0)*E_100 + (1.0/3.0)*P_100;
    } else {
        // Project weight rises linearly from 0 (E_100 = 40) to 1/3 (E_100 = 60)
        double project_weight{ (1.0/3.0)*(E_100 - 40.0)/20.0 };
        final_grade = project_weight*P_100 + (1.0 - project_weight)*E_100;
    }

    final_grade = std::round( final_grade + 1e-12 );

    std::cout << "Final grade: " << final_grade << std::endl;

    return 0;
}
