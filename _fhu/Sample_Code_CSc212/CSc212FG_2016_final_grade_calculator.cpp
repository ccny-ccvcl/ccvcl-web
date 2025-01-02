//
//  CSc212FG_2016_final_grade_calculator.cpp
//  Grade_Generator
//
//  Created by Feng Hu on 12/19/16.
//  Copyright © 2016 Feng Hu. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    // Replace the following example input with your own scores: index 0 to 5 for Quiz 1-6, index 6 to 8 for attendance, index 9 to 14 for assignments 1-6, index 15 to 17 for exams 1-3, and index 18 for bonus and extra credits. (replace your A, if any, with 8.5 for quiz, and 1 for attendance).
    double raw_scores[19] = {10,10,10,10,10,10,1,1,1,99,97,100,99,93,91,65,93,91,5};
    
    // Quizzes
    double quiz_score = 1;
    for (int i = 0; i < 6; ++i) {
        if (raw_scores[i] != 0) {
            quiz_score += 0.6 + raw_scores[i] * 0.04;
        }
    }
    
    // Attendances
    double attendance_score = 0;
    for (int i = 6; i < 9; ++i) {
        attendance_score += raw_scores[i];
    }
    std::cout << "You get " << quiz_score + attendance_score << " points out of 10 points for Quiz and Attendance." << std::endl;
    
    // Assignments
    double assignment_score = 0;
    for (int i = 9; i < 15; ++i) {
        assignment_score += raw_scores[i] / 100 * 5;
    }
    std::cout << "You get " << assignment_score << " points out of 30 points for the 6 assignments." << std::endl;
    
    // Exams
    double exam_score = 0;
    for (int i = 15; i < 18; ++i) {
        exam_score += raw_scores[i] / 100 * 20;
    }
    std::cout << "You get " << exam_score << " points out of 60 points for the 3 exams." << std::endl;
    
    // Bonus and extra credits (Maximum 5 points)
    double bonus_and_extra_credits = std::min(5.0, raw_scores[18]);
    std::cout << "You get " << bonus_and_extra_credits << " points out of the maximum 5 points for bonus (rewards for improvement) and extra credits (feedback about the course)." << std::endl;
    
    double final_score;
    final_score = quiz_score + attendance_score + assignment_score + + exam_score +bonus_and_extra_credits;
    std::cout << "You final score is " << final_score << " points out of 100 points for this course." << std::endl;
    
    // Final score scale
    std::string final_score_scale;
    if (final_score >= 95) {
        final_score_scale = "A+";
    }else if (final_score >= 90){
        final_score_scale = "A";
    }else if (final_score >= 85){
        final_score_scale = "A-";
    }else if (final_score >= 80){
        final_score_scale = "B+";
    }else if (final_score >= 75){
        final_score_scale = "B";
    }else if (final_score >= 70){
        final_score_scale = "B-";
    }else if (final_score >= 65){
        final_score_scale = "C+";
    }else if (final_score >= 60){
        final_score_scale = "C";
    }else{
        final_score_scale = "F";
    }
    std::cout << "You final score in terms of ABCDF is " << final_score_scale << " for 2016 CSc212FG Data Structures." << std::endl;
}
