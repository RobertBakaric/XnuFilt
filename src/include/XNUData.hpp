/*
 * XNUData.hpp
 * 
 * Copyright 2015 Robert Bakaric <rbakaric@irb.hr>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <vector>
#include <string>

using namespace std;

namespace xnu{

/**
 * @brief XnuScores class containing default matrices and parameters.
 */

class XnuScores {
  
  protected:

/*! Lambda for PAM60 matrix
 * @par Lambda60 = 0.346574
 */
  double Lambda60;
  
/*! Lambda for PAM120 matrix
 * @par Lambda120 = 0.346574
 */
  double Lambda120;
  
/*! Lambda for PAM250 matrix
 * @par Lambda250 = 0.231049
 */
  double Lambda250;
  
  
/*! Mdm matrix
 * 
 * @code
     M     = { 9867,  2,  9, 10,  3,  8, 17, 21,  2,  6,  4,  2,  6,  2, 22, 35, 32, 0,  2, 18,
                  1, 9913,  1,  0,  1, 10,  0,  0, 10,  3,  1, 19,  4,  1,  4,  6,  1, 8,  0,  1,
                  4,  1, 9822, 36,  0,  4,  6,  6, 21,  3,  1, 13,  0,  1,  2, 20,  9, 1,  4,  1,
                  6,  0, 42, 9859,  0,  6, 53,  6,  4,  1,  0,  3,  0,  0,  1,  5,  3, 0,  0,  1,
                  1,  1,  0,  0, 9973,  0,  0,  0,  1,  1,  0,  0,  0,  0,  1,  5,  1, 0,  3,  2,
                  3,  9,  4,  5,  0, 9876, 27,  1, 23,  1,  3,  6,  4,  0,  6,  2,  2, 0,  0,  1,
                 10,  0,  7, 56,  0, 35, 9865,  4,  2,  3,  1,  4,  1,  0,  3,  4,  2, 0,  1,  2,
                 21,  1, 12, 11,  1,  3,  7, 9935,  1,  0,  1,  2,  1,  1,  3, 21,  3, 0,  0,  5,
                  1,  8, 18,  3,  1, 20,  1,  0, 9912,  0,  1,  1,  0,  2,  3,  1,  1, 1,  4,  1,
                  2,  2,  3,  1,  2,  1,  2,  0,  0, 9872,  9,  2, 12,  7,  0,  1,  7, 0,  1, 33,
                  3,  1,  3,  0,  0,  6,  1,  1,  4, 22, 9947,  2, 45, 13,  3,  1,  3, 4,  2, 15,
                  2, 37, 25,  6,  0, 12,  7,  2,  2,  4,  1, 9926, 20,  0,  3,  8, 11, 0,  1,  1,
                  1,  1,  0,  0,  0,  2,  0,  0,  0,  5,  8,  4, 9874,  1,  0,  1,  2, 0,  0,  4,
                  1,  1,  1,  0,  0,  0,  0,  1,  2,  8,  6,  0,  4, 9946,  0,  2,  1, 3, 28,  0,
                 13,  5,  2,  1,  1,  8,  3,  2,  5,  1,  2,  2,  1,  1, 9926, 12,  4, 0,  0,  2,
                 28, 11, 34,  7, 11,  4,  6, 16,  2,  2,  1,  7,  4,  3, 17, 9840, 38, 5,  2,  2,
                 22,  2, 13,  4,  1,  3,  2,  2,  1, 11,  2,  8,  6,  1,  5, 32, 9871, 0,  2,  9,
                  0,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  1,  0, 9976, 1,  0,
                  1,  0,  3,  0,  3,  0,  1,  0,  4,  1,  1,  0,  0, 21,  0,  1,  1, 2, 9945,  1,
                 13,  2,  1,  1,  3,  2,  2,  3,  3, 57, 11,  1, 17,  1,  3,  2, 10, 0, 2, 9901};
   @endcode
   */
  vector<int> M;
/*!
 * 
 This matrix was produced by "pam" Version 1.0.2 [18-Sep-91]

 PAM 60 substitution matrix, scale = ln(2)/2 = 0.346574

 Lowest score = -12, Highest score = 13
 @code

        Pam60 = {{  5,  -5,  -2,  -2,  -5,  -3,  -1,   0,  -5,  -3,  -4,  -5,  -3,  -6,   0,   1,   1, -10,  -6,  -1,  -1,  -1,   0, -12, -999999},
                 { -5,   8,  -3,  -6,  -6,   0,  -6,  -7,   0,  -4,  -6,   2,  -2,  -7,  -2,  -2,  -4,   0,  -8,  -5,  -3,  -1,   0, -12, -999999},
                 { -2,  -3,   6,   2,  -7,  -2,   0,  -1,   1,  -4,  -5,   0,  -6,  -6,  -4,   1,  -1,  -6,  -3,  -5,   6,   0,   0, -12, -999999},
                 { -2,  -6,   2,   7, -10,  -1,   3,  -2,  -2,  -5,  -9,  -2,  -7, -11,  -5,  -2,  -3, -11,  -8,  -6,   6,   3,   0, -12, -999999},
                 { -5,  -6,  -7, -10,   9, -10, -10,  -7,  -6,  -4, -11, -10, -10,  -9,  -6,  -1,  -5, -12,  -2,  -4,  -8,  -9,   0, -12, -999999},
                 { -3,   0,  -2,  -1, -10,   7,   2,  -5,   2,  -5,  -3,  -1,  -2,  -9,  -1,  -3,  -4,  -9,  -8,  -5,   0,   7,   0, -12, -999999},
                 { -1,  -6,   0,   3, -10,   2,   7,  -2,  -3,  -4,  -7,  -3,  -5, -10,  -3,  -2,  -4, -12,  -7,  -4,   3,   6,   0, -12, -999999},
                 {  0,  -7,  -1,  -2,  -7,  -5,  -2,   6,  -6,  -7,  -8,  -5,  -6,  -7,  -4,   0,  -3, -11, -10,  -4,  -1,  -2,   0, -12, -999999},
                 { -5,   0,   1,  -2,  -6,   2,  -3,  -6,   8,  -6,  -4,  -4,  -7,  -4,  -2,  -4,  -5,  -5,  -2,  -5,   1,   1,   0, -12, -999999},
                 { -3,  -4,  -4,  -5,  -4,  -5,  -4,  -7,  -6,   7,   0,  -4,   1,  -1,  -6,  -4,  -1, -10,  -4,   3,  -3,  -4,   0, -12, -999999},
                 { -4,  -6,  -5,  -9, -11,  -3,  -7,  -8,  -4,   0,   6,  -6,   2,  -1,  -5,  -6,  -5,  -4,  -5,  -1,  -6,  -4,   0, -12, -999999},
                 { -5,   2,   0,  -2, -10,  -1,  -3,  -5,  -4,  -4,  -6,   6,   0, -10,  -4,  -2,  -2,  -8,  -7,  -6,   0,  -1,   0, -12, -999999},
                 { -3,  -2,  -6,  -7, -10,  -2,  -5,  -6,  -7,   1,   2,   0,  10,  -2,  -6,  -4,  -2,  -9,  -7,   0,  -5,  -2,   0, -12, -999999},
                 { -6,  -7,  -6, -11,  -9,  -9, -10,  -7,  -4,  -1,  -1, -10,  -2,   8,  -7,  -5,  -6,  -3,   3,  -5,  -7,  -9,   0, -12, -999999},
                 {  0,  -2,  -4,  -5,  -6,  -1,  -3,  -4,  -2,  -6,  -5,  -4,  -6,  -7,   7,   0,  -2, -10, -10,  -4,  -3,  -1,   0, -12, -999999},
                 {  1,  -2,   1,  -2,  -1,  -3,  -2,   0,  -4,  -4,  -6,  -2,  -4,  -5,   0,   5,   1,  -4,  -5,  -4,   1,  -2,   0, -12, -999999},
                 {  1,  -4,  -1,  -3,  -5,  -4,  -4,  -3,  -5,  -1,  -5,  -2,  -2,  -6,  -2,   1,   6,  -9,  -5,  -1,   0,  -3,   0, -12, -999999},
                 {-10,   0,  -6, -11, -12,  -9, -12, -11,  -5, -10,  -4,  -8,  -9,  -3, -10,  -4,  -9,  13,  -3, -11,  -7,  -9,   0, -12, -999999},
                 { -6,  -8,  -3,  -8,  -2,  -8,  -7, -10,  -2,  -4,  -5,  -7,  -7,   3, -10,  -5,  -5,  -3,   9,  -5,  -4,  -6,   0, -12, -999999},
                 { -1,  -5,  -5,  -6,  -4,  -5,  -4,  -4,  -5,   3,  -1,  -6,   0,  -5,  -4,  -4,  -1, -11,  -5,   6,  -4,  -4,   0, -12, -999999},
                 { -1,  -3,   6,   6,  -8,   0,   3,  -1,   1,  -3,  -6,   0,  -5,  -7,  -3,   1,   0,  -7,  -4,  -4,   7,   3,   0, -12, -999999},
                 { -1,  -1,   0,   3,  -9,   7,   6,  -2,   1,  -4,  -4,  -1,  -2,  -9,  -1,  -2,  -3,  -9,  -6,  -4,   3,   7,   0, -12, -999999},
                 {  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, -12, -999999},
                 {-12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12,   1, -999999},
                 {-999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, 
                 -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999 }};
@endcode
*/
  vector<vector<int>> Pam60;
/*!
 * 
 This matrix was produced by "pam" Version 1.0.2, [18-Sep-91]

 PAM 120, substitution matrix, scale = ln(2)/2, = 0.346574

 Lowest score = -8, Highest score = 12
@code
         Pam120 = {{ 3, -3, -1,  0, -3, -1,  0,  1, -3, -1, -3, -2, -2, -4,  1,  1,  1, -7, -4,  0,  1,  0,  0, -8, -999999},
                   {-3,  6, -1, -3, -4,  1, -3, -4,  1, -2, -4,  2, -1, -5, -1, -1, -2,  1, -5, -3, -1,  0,  0, -8, -999999},
                   {-1, -1,  4,  2, -5,  0,  1,  0,  2, -2, -4,  1, -3, -4, -2,  1,  0, -4, -2, -3,  4,  1,  0, -8, -999999},
                   { 0, -3,  2,  5, -7,  1,  3,  0,  0, -3, -5, -1, -4, -7, -3,  0, -1, -8, -5, -3,  5,  3,  0, -8, -999999},
                   {-3, -4, -5, -7,  9, -7, -7, -4, -4, -3, -7, -7, -6, -6, -4,  0, -3, -8, -1, -3, -4, -6,  0, -8, -999999},
                   {-1,  1,  0,  1, -7,  6,  2, -3,  3, -3, -2,  0, -1, -6,  0, -2, -2, -6, -5, -3,  1,  5,  0, -8, -999999},
                   { 0, -3,  1,  3, -7,  2,  5, -1, -1, -3, -4, -1, -3, -7, -2, -1, -2, -8, -5, -3,  3,  5,  0, -8, -999999},
                   { 1, -4,  0,  0, -4, -3, -1,  5, -4, -4, -5, -3, -4, -5, -2,  1, -1, -8, -6, -2,  1, -1,  0, -8, -999999},
                   {-3,  1,  2,  0, -4,  3, -1, -4,  7, -4, -3, -2, -4, -3, -1, -2, -3, -3, -1, -3,  2,  2,  0, -8, -999999},
                   {-1, -2, -2, -3, -3, -3, -3, -4, -4,  6,  1, -3,  1,  0, -3, -2,  0, -6, -2,  3, -2, -2,  0, -8, -999999},
                   {-3, -4, -4, -5, -7, -2, -4, -5, -3,  1,  5, -4,  3,  0, -3, -4, -3, -3, -2,  1, -3, -2,  0, -8, -999999},
                   {-2,  2,  1, -1, -7,  0, -1, -3, -2, -3, -4,  5,  0, -7, -2, -1, -1, -5, -5, -4,  1,  0,  0, -8, -999999},
                   {-2, -1, -3, -4, -6, -1, -3, -4, -4,  1,  3,  0,  8, -1, -3, -2, -1, -6, -4,  1, -3, -1,  0, -8, -999999},
                   {-4, -5, -4, -7, -6, -6, -7, -5, -3,  0,  0, -7, -1,  8, -5, -3, -4, -1,  4, -3, -4, -5,  0, -8, -999999},
                   { 1, -1, -2, -3, -4,  0, -2, -2, -1, -3, -3, -2, -3, -5,  6,  1, -1, -7, -6, -2, -1,  0,  0, -8, -999999},
                   { 1, -1,  1,  0,  0, -2, -1,  1, -2, -2, -4, -1, -2, -3,  1,  3,  2, -2, -3, -2,  1,  0,  0, -8, -999999},
                   { 1, -2,  0, -1, -3, -2, -2, -1, -3,  0, -3, -1, -1, -4, -1,  2,  4, -6, -3,  0,  1, -1,  0, -8, -999999},
                   {-7,  1, -4, -8, -8, -6, -8, -8, -3, -6, -3, -5, -6, -1, -7, -2, -6, 12, -2, -8, -5, -6,  0, -8, -999999},
                   {-4, -5, -2, -5, -1, -5, -5, -6, -1, -2, -2, -5, -4,  4, -6, -3, -3, -2,  8, -3, -2, -4,  0, -8, -999999},
                   { 0, -3, -3, -3, -3, -3, -3, -2, -3,  3,  1, -4,  1, -3, -2, -2,  0, -8, -3,  5, -2, -2,  0, -8, -999999},
                   { 1, -1,  4,  5, -4,  1,  3,  1,  2, -2, -3,  1, -3, -4, -1,  1,  1, -5, -2, -2,  6,  4,  0, -8, -999999},
                   { 0,  0,  1,  3, -6,  5,  5, -1,  2, -2, -2,  0, -1, -5,  0,  0, -1, -6, -4, -2,  4,  6,  0, -8, -999999},
                   { 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -8, -999999},
                   {-8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,  1, -999999},
                   {-999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, 
                    -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999}};
@endcode
*/
  vector<vector<int>> Pam120;
/*!
  
 This matrix was produced by "pam" Version 1.0.2, [18-Sep-91]

 PAM 250, substitution matrix, scale = ln(2)/3, = 0.231049

 Lowest score = -8, Highest score = 17
@code
          Pam250 = {{ 2, -2,  0,  0, -2,  0,  0,  1, -1, -1, -2, -1, -1, -3,  1,  1,  1, -6, -3,  0,  2,  1,  0, -8, -999999},
                    {-2,  6,  0, -1, -4,  1, -1, -3,  2, -2, -3,  3,  0, -4,  0,  0, -1,  2, -4, -2,  1,  2,  0, -8, -999999},
                    { 0,  0,  2,  2, -4,  1,  1,  0,  2, -2, -3,  1, -2, -3,  0,  1,  0, -4, -2, -2,  4,  3,  0, -8, -999999},
                    { 0, -1,  2,  4, -5,  2,  3,  1,  1, -2, -4,  0, -3, -6, -1,  0,  0, -7, -4, -2,  5,  4,  0, -8, -999999},
                    {-2, -4, -4, -5, 12, -5, -5, -3, -3, -2, -6, -5, -5, -4, -3,  0, -2, -8,  0, -2, -3, -4,  0, -8, -999999},
                    { 0,  1,  1,  2, -5,  4,  2, -1,  3, -2, -2,  1, -1, -5,  0, -1, -1, -5, -4, -2,  3,  5,  0, -8, -999999},
                    { 0, -1,  1,  3, -5,  2,  4,  0,  1, -2, -3,  0, -2, -5, -1,  0,  0, -7, -4, -2,  4,  5,  0, -8, -999999},
                    { 1, -3,  0,  1, -3, -1,  0,  5, -2, -3, -4, -2, -3, -5,  0,  1,  0, -7, -5, -1,  2,  1,  0, -8, -999999},
                    {-1,  2,  2,  1, -3,  3,  1, -2,  6, -2, -2,  0, -2, -2,  0, -1, -1, -3,  0, -2,  3,  3,  0, -8, -999999},
                    {-1, -2, -2, -2, -2, -2, -2, -3, -2,  5,  2, -2,  2,  1, -2, -1,  0, -5, -1,  4, -1, -1,  0, -8, -999999},
                    {-2, -3, -3, -4, -6, -2, -3, -4, -2,  2,  6, -3,  4,  2, -3, -3, -2, -2, -1,  2, -2, -1,  0, -8, -999999},
                    {-1,  3,  1,  0, -5,  1,  0, -2,  0, -2, -3,  5,  0, -5, -1,  0,  0, -3, -4, -2,  2,  2,  0, -8, -999999},
                    {-1,  0, -2, -3, -5, -1, -2, -3, -2,  2,  4,  0,  6,  0, -2, -2, -1, -4, -2,  2, -1,  0,  0, -8, -999999},
                    {-3, -4, -3, -6, -4, -5, -5, -5, -2,  1,  2, -5,  0,  9, -5, -3, -3,  0,  7, -1, -3, -4,  0, -8, -999999},
                    { 1,  0,  0, -1, -3,  0, -1,  0,  0, -2, -3, -1, -2, -5,  6,  1,  0, -6, -5, -1,  1,  1,  0, -8, -999999},
                    { 1,  0,  1,  0,  0, -1,  0,  1, -1, -1, -3,  0, -2, -3,  1,  2,  1, -2, -3, -1,  2,  1,  0, -8, -999999},
                    { 1, -1,  0,  0, -2, -1,  0,  0, -1,  0, -2,  0, -1, -3,  0,  1,  3, -5, -3,  0,  2,  1,  0, -8, -999999},
                    {-6,  2, -4, -7, -8, -5, -7, -7, -3, -5, -2, -3, -4,  0, -6, -2, -5, 17,  0, -6, -4, -4,  0, -8, -999999},
                    {-3, -4, -2, -4,  0, -4, -4, -5,  0, -1, -1, -4, -2,  7, -5, -3, -3,  0, 10, -2, -2, -3,  0, -8, -999999},
                    { 0, -2, -2, -2, -2, -2, -2, -1, -2,  4,  2, -2,  2, -1, -1, -1,  0, -6, -2,  4,  0,  0,  0, -8, -999999},
                    { 2,  1,  4,  5, -3,  3,  4,  2,  3, -1, -2,  2, -1, -3,  1,  2,  2, -4, -2,  0,  6,  5,  0, -8, -999999},
                    { 1,  2,  3,  4, -4,  5,  5,  1,  3, -1, -1,  2,  0, -4,  1,  1,  1, -4, -3,  0,  5,  6,  0, -8, -999999},
                    { 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -8, -999999},
                    {-8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,  1, -999999},
                    {-999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, 
                     -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999 }};
   @endcode
   */
  vector<vector<int>> Pam250;
  
/*! The protein Alphabet
 * @par Alphabet ="ARNDCQEGHILKMFPSTWYVBZX*-";
 */
  string Alphabet;
/*!
 * @par Dayhoff = {0.087, 0.041, 0.040, 0.047, 0.033, 0.038, 0.050, 0.088, 0.034, 0.037, 0.085, 0.081, 0.015, 0.040, 0.051, 0.070, 0.058, 0.010, 0.030, 0.065};
 */
  vector<double> Dayhoff;
/*!
 * @par Blast = {  0.081, 0.057, 0.045, 0.054, 0.015, 0.039, 0.061, 0.068, 0.022, 0.057, 0.093, 0.056, 0.025, 0.040, 0.049, 0.068, 0.058, 0.013, 0.032, 0.067 };
 */
  vector<double> Blast;
  
  public:
/*!
 * XnuScores  constructor
 * 
 */
  XnuScores():Lambda60(0.346574),Lambda120(0.346574),Lambda250(0.231049){
     
     Alphabet ="ARNDCQEGHILKMFPSTWYVBZX*-";
     
     Dayhoff = {0.087, 0.041, 0.040, 0.047, 0.033, 0.038, 0.050, 0.088, 0.034, 0.037,
	             0.085, 0.081, 0.015, 0.040, 0.051, 0.070, 0.058, 0.010, 0.030, 0.065};
                
     Blast = {  0.081, 0.057, 0.045, 0.054, 0.015, 0.039, 0.061, 0.068, 0.022, 0.057,
	             0.093, 0.056, 0.025, 0.040, 0.049, 0.068, 0.058, 0.013, 0.032, 0.067 };
     
     M     = { 9867,  2,  9, 10,  3,  8, 17, 21,  2,  6,  4,  2,  6,  2, 22, 35, 32, 0,  2, 18,
               1, 9913,  1,  0,  1, 10,  0,  0, 10,  3,  1, 19,  4,  1,  4,  6,  1, 8,  0,  1,
               4,  1, 9822, 36,  0,  4,  6,  6, 21,  3,  1, 13,  0,  1,  2, 20,  9, 1,  4,  1,
               6,  0, 42, 9859,  0,  6, 53,  6,  4,  1,  0,  3,  0,  0,  1,  5,  3, 0,  0,  1,
               1,  1,  0,  0, 9973,  0,  0,  0,  1,  1,  0,  0,  0,  0,  1,  5,  1, 0,  3,  2,
               3,  9,  4,  5,  0, 9876, 27,  1, 23,  1,  3,  6,  4,  0,  6,  2,  2, 0,  0,  1,
               10,  0,  7, 56,  0, 35, 9865,  4,  2,  3,  1,  4,  1,  0,  3,  4,  2, 0,  1,  2,
               21,  1, 12, 11,  1,  3,  7, 9935,  1,  0,  1,  2,  1,  1,  3, 21,  3, 0,  0,  5,
               1,  8, 18,  3,  1, 20,  1,  0, 9912,  0,  1,  1,  0,  2,  3,  1,  1, 1,  4,  1,
               2,  2,  3,  1,  2,  1,  2,  0,  0, 9872,  9,  2, 12,  7,  0,  1,  7, 0,  1, 33,
               3,  1,  3,  0,  0,  6,  1,  1,  4, 22, 9947,  2, 45, 13,  3,  1,  3, 4,  2, 15,
               2, 37, 25,  6,  0, 12,  7,  2,  2,  4,  1, 9926, 20,  0,  3,  8, 11, 0,  1,  1,
               1,  1,  0,  0,  0,  2,  0,  0,  0,  5,  8,  4, 9874,  1,  0,  1,  2, 0,  0,  4,
               1,  1,  1,  0,  0,  0,  0,  1,  2,  8,  6,  0,  4, 9946,  0,  2,  1, 3, 28,  0,
               13,  5,  2,  1,  1,  8,  3,  2,  5,  1,  2,  2,  1,  1, 9926, 12,  4, 0,  0,  2,
               28, 11, 34,  7, 11,  4,  6, 16,  2,  2,  1,  7,  4,  3, 17, 9840, 38, 5,  2,  2,
               22,  2, 13,  4,  1,  3,  2,  2,  1, 11,  2,  8,  6,  1,  5, 32, 9871, 0,  2,  9,
               0,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  1,  0, 9976, 1,  0,
               1,  0,  3,  0,  3,  0,  1,  0,  4,  1,  1,  0,  0, 21,  0,  1,  1, 2, 9945,  1,
               13,  2,  1,  1,  3,  2,  2,  3,  3, 57, 11,  1, 17,  1,  3,  2, 10, 0, 2, 9901};
        

        Pam60 = {{ 5,  -5,  -2,  -2,  -5,  -3,  -1,   0,  -5,  -3,  -4,  -5,  -3,  -6,   0,   1,   1, -10,  -6,  -1,  -1,  -1,   0, -12, -999999},
                 {-5,   8,  -3,  -6,  -6,   0,  -6,  -7,   0,  -4,  -6,   2,  -2,  -7,  -2,  -2,  -4,   0,  -8,  -5,  -3,  -1,   0, -12, -999999},
                 {-2,  -3,   6,   2,  -7,  -2,   0,  -1,   1,  -4,  -5,   0,  -6,  -6,  -4,   1,  -1,  -6,  -3,  -5,   6,   0,   0, -12, -999999},
                 {-2,  -6,   2,   7, -10,  -1,   3,  -2,  -2,  -5,  -9,  -2,  -7, -11,  -5,  -2,  -3, -11,  -8,  -6,   6,   3,   0, -12, -999999},
                 {-5,  -6,  -7, -10,   9, -10, -10,  -7,  -6,  -4, -11, -10, -10,  -9,  -6,  -1,  -5, -12,  -2,  -4,  -8,  -9,   0, -12, -999999},
                 {-3,   0,  -2,  -1, -10,   7,   2,  -5,   2,  -5,  -3,  -1,  -2,  -9,  -1,  -3,  -4,  -9,  -8,  -5,   0,   7,   0, -12, -999999},
                 {-1,  -6,   0,   3, -10,   2,   7,  -2,  -3,  -4,  -7,  -3,  -5, -10,  -3,  -2,  -4, -12,  -7,  -4,   3,   6,   0, -12, -999999},
                 { 0,  -7,  -1,  -2,  -7,  -5,  -2,   6,  -6,  -7,  -8,  -5,  -6,  -7,  -4,   0,  -3, -11, -10,  -4,  -1,  -2,   0, -12, -999999},
                 {-5,   0,   1,  -2,  -6,   2,  -3,  -6,   8,  -6,  -4,  -4,  -7,  -4,  -2,  -4,  -5,  -5,  -2,  -5,   1,   1,   0, -12, -999999},
                 {-3,  -4,  -4,  -5,  -4,  -5,  -4,  -7,  -6,   7,   0,  -4,   1,  -1,  -6,  -4,  -1, -10,  -4,   3,  -3,  -4,   0, -12, -999999},
                 {-4,  -6,  -5,  -9, -11,  -3,  -7,  -8,  -4,   0,   6,  -6,   2,  -1,  -5,  -6,  -5,  -4,  -5,  -1,  -6,  -4,   0, -12, -999999},
                 {-5,   2,   0,  -2, -10,  -1,  -3,  -5,  -4,  -4,  -6,   6,   0, -10,  -4,  -2,  -2,  -8,  -7,  -6,   0,  -1,   0, -12, -999999},
                 {-3,  -2,  -6,  -7, -10,  -2,  -5,  -6,  -7,   1,   2,   0,  10,  -2,  -6,  -4,  -2,  -9,  -7,   0,  -5,  -2,   0, -12, -999999},
                 {-6,  -7,  -6, -11,  -9,  -9, -10,  -7,  -4,  -1,  -1, -10,  -2,   8,  -7,  -5,  -6,  -3,   3,  -5,  -7,  -9,   0, -12, -999999},
                 { 0,  -2,  -4,  -5,  -6,  -1,  -3,  -4,  -2,  -6,  -5,  -4,  -6,  -7,   7,   0,  -2, -10, -10,  -4,  -3,  -1,   0, -12, -999999},
                 { 1,  -2,   1,  -2,  -1,  -3,  -2,   0,  -4,  -4,  -6,  -2,  -4,  -5,   0,   5,   1,  -4,  -5,  -4,   1,  -2,   0, -12, -999999},
                 { 1,  -4,  -1,  -3,  -5,  -4,  -4,  -3,  -5,  -1,  -5,  -2,  -2,  -6,  -2,   1,   6,  -9,  -5,  -1,   0,  -3,   0, -12, -999999},
                 {-10,   0,  -6, -11, -12,  -9, -12, -11,  -5, -10,  -4,  -8,  -9,  -3, -10,  -4,  -9,  13,  -3, -11,  -7,  -9,   0, -12, -999999},
                 {-6,  -8,  -3,  -8,  -2,  -8,  -7, -10,  -2,  -4,  -5,  -7,  -7,   3, -10,  -5,  -5,  -3,   9,  -5,  -4,  -6,   0, -12, -999999},
                 {-1,  -5,  -5,  -6,  -4,  -5,  -4,  -4,  -5,   3,  -1,  -6,   0,  -5,  -4,  -4,  -1, -11,  -5,   6,  -4,  -4,   0, -12, -999999},
                 {-1,  -3,   6,   6,  -8,   0,   3,  -1,   1,  -3,  -6,   0,  -5,  -7,  -3,   1,   0,  -7,  -4,  -4,   7,   3,   0, -12, -999999},
                 {-1,  -1,   0,   3,  -9,   7,   6,  -2,   1,  -4,  -4,  -1,  -2,  -9,  -1,  -2,  -3,  -9,  -6,  -4,   3,   7,   0, -12, -999999},
                 { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, -12, -999999},
                 {-12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12,   1, -999999},
                 {-999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, 
                 -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999 }};

         Pam120 = {{ 3, -3, -1,  0, -3, -1,  0,  1, -3, -1, -3, -2, -2, -4,  1,  1,  1, -7, -4,  0,  1,  0,  0, -8, -999999},
                   {-3,  6, -1, -3, -4,  1, -3, -4,  1, -2, -4,  2, -1, -5, -1, -1, -2,  1, -5, -3, -1,  0,  0, -8, -999999},
                   {-1, -1,  4,  2, -5,  0,  1,  0,  2, -2, -4,  1, -3, -4, -2,  1,  0, -4, -2, -3,  4,  1,  0, -8, -999999},
                   { 0, -3,  2,  5, -7,  1,  3,  0,  0, -3, -5, -1, -4, -7, -3,  0, -1, -8, -5, -3,  5,  3,  0, -8, -999999},
                   {-3, -4, -5, -7,  9, -7, -7, -4, -4, -3, -7, -7, -6, -6, -4,  0, -3, -8, -1, -3, -4, -6,  0, -8, -999999},
                   {-1,  1,  0,  1, -7,  6,  2, -3,  3, -3, -2,  0, -1, -6,  0, -2, -2, -6, -5, -3,  1,  5,  0, -8, -999999},
                   { 0, -3,  1,  3, -7,  2,  5, -1, -1, -3, -4, -1, -3, -7, -2, -1, -2, -8, -5, -3,  3,  5,  0, -8, -999999},
                   {1, -4,  0,  0, -4, -3, -1,  5, -4, -4, -5, -3, -4, -5, -2,  1, -1, -8, -6, -2,  1, -1,  0, -8, -999999},
                   {-3,  1,  2,  0, -4,  3, -1, -4,  7, -4, -3, -2, -4, -3, -1, -2, -3, -3, -1, -3,  2,  2,  0, -8, -999999},
                   {-1, -2, -2, -3, -3, -3, -3, -4, -4,  6,  1, -3,  1,  0, -3, -2,  0, -6, -2,  3, -2, -2,  0, -8, -999999},
                   {-3, -4, -4, -5, -7, -2, -4, -5, -3,  1,  5, -4,  3,  0, -3, -4, -3, -3, -2,  1, -3, -2,  0, -8, -999999},
                   {-2,  2,  1, -1, -7,  0, -1, -3, -2, -3, -4,  5,  0, -7, -2, -1, -1, -5, -5, -4,  1,  0,  0, -8, -999999},
                   {-2, -1, -3, -4, -6, -1, -3, -4, -4,  1,  3,  0,  8, -1, -3, -2, -1, -6, -4,  1, -3, -1,  0, -8, -999999},
                   {-4, -5, -4, -7, -6, -6, -7, -5, -3,  0,  0, -7, -1,  8, -5, -3, -4, -1,  4, -3, -4, -5,  0, -8, -999999},
                   {1, -1, -2, -3, -4,  0, -2, -2, -1, -3, -3, -2, -3, -5,  6,  1, -1, -7, -6, -2, -1,  0,  0, -8, -999999},
                   {1, -1,  1,  0,  0, -2, -1,  1, -2, -2, -4, -1, -2, -3,  1,  3,  2, -2, -3, -2,  1,  0,  0, -8, -999999},
                   {1, -2,  0, -1, -3, -2, -2, -1, -3,  0, -3, -1, -1, -4, -1,  2,  4, -6, -3,  0,  1, -1,  0, -8, -999999},
                   {-7,  1, -4, -8, -8, -6, -8, -8, -3, -6, -3, -5, -6, -1, -7, -2, -6, 12, -2, -8, -5, -6,  0, -8, -999999},
                   {-4, -5, -2, -5, -1, -5, -5, -6, -1, -2, -2, -5, -4,  4, -6, -3, -3, -2,  8, -3, -2, -4,  0, -8, -999999},
                   {0, -3, -3, -3, -3, -3, -3, -2, -3,  3,  1, -4,  1, -3, -2, -2,  0, -8, -3,  5, -2, -2,  0, -8, -999999},
                   {1, -1,  4,  5, -4,  1,  3,  1,  2, -2, -3,  1, -3, -4, -1,  1,  1, -5, -2, -2,  6,  4,  0, -8, -999999},
                   {0,  0,  1,  3, -6,  5,  5, -1,  2, -2, -2,  0, -1, -5,  0,  0, -1, -6, -4, -2,  4,  6,  0, -8, -999999},
                   {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -8, -999999},
                   {-8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,  1, -999999},
                   {-999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, 
                    -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999}};

          Pam250 = {{2, -2,  0,  0, -2,  0,  0,  1, -1, -1, -2, -1, -1, -3,  1,  1,  1, -6, -3,  0,  2,  1,  0, -8, -999999},
                    {-2,  6,  0, -1, -4,  1, -1, -3,  2, -2, -3,  3,  0, -4,  0,  0, -1,  2, -4, -2,  1,  2,  0, -8, -999999},
                    {0,  0,  2,  2, -4,  1,  1,  0,  2, -2, -3,  1, -2, -3,  0,  1,  0, -4, -2, -2,  4,  3,  0, -8, -999999},
                    {0, -1,  2,  4, -5,  2,  3,  1,  1, -2, -4,  0, -3, -6, -1,  0,  0, -7, -4, -2,  5,  4,  0, -8, -999999},
                    {-2, -4, -4, -5, 12, -5, -5, -3, -3, -2, -6, -5, -5, -4, -3,  0, -2, -8,  0, -2, -3, -4,  0, -8, -999999},
                    {0,  1,  1,  2, -5,  4,  2, -1,  3, -2, -2,  1, -1, -5,  0, -1, -1, -5, -4, -2,  3,  5,  0, -8, -999999},
                    {0, -1,  1,  3, -5,  2,  4,  0,  1, -2, -3,  0, -2, -5, -1,  0,  0, -7, -4, -2,  4,  5,  0, -8, -999999},
                    {1, -3,  0,  1, -3, -1,  0,  5, -2, -3, -4, -2, -3, -5,  0,  1,  0, -7, -5, -1,  2,  1,  0, -8, -999999},
                    {-1,  2,  2,  1, -3,  3,  1, -2,  6, -2, -2,  0, -2, -2,  0, -1, -1, -3,  0, -2,  3,  3,  0, -8, -999999},
                    {-1, -2, -2, -2, -2, -2, -2, -3, -2,  5,  2, -2,  2,  1, -2, -1,  0, -5, -1,  4, -1, -1,  0, -8, -999999},
                    {-2, -3, -3, -4, -6, -2, -3, -4, -2,  2,  6, -3,  4,  2, -3, -3, -2, -2, -1,  2, -2, -1,  0, -8, -999999},
                    {-1,  3,  1,  0, -5,  1,  0, -2,  0, -2, -3,  5,  0, -5, -1,  0,  0, -3, -4, -2,  2,  2,  0, -8, -999999},
                    {-1,  0, -2, -3, -5, -1, -2, -3, -2,  2,  4,  0,  6,  0, -2, -2, -1, -4, -2,  2, -1,  0,  0, -8, -999999},
                    {-3, -4, -3, -6, -4, -5, -5, -5, -2,  1,  2, -5,  0,  9, -5, -3, -3,  0,  7, -1, -3, -4,  0, -8, -999999},
                    {1,  0,  0, -1, -3,  0, -1,  0,  0, -2, -3, -1, -2, -5,  6,  1,  0, -6, -5, -1,  1,  1,  0, -8, -999999},
                    {1,  0,  1,  0,  0, -1,  0,  1, -1, -1, -3,  0, -2, -3,  1,  2,  1, -2, -3, -1,  2,  1,  0, -8, -999999},
                    {1, -1,  0,  0, -2, -1,  0,  0, -1,  0, -2,  0, -1, -3,  0,  1,  3, -5, -3,  0,  2,  1,  0, -8, -999999},
                    {-6,  2, -4, -7, -8, -5, -7, -7, -3, -5, -2, -3, -4,  0, -6, -2, -5, 17,  0, -6, -4, -4,  0, -8, -999999},
                    {-3, -4, -2, -4,  0, -4, -4, -5,  0, -1, -1, -4, -2,  7, -5, -3, -3,  0, 10, -2, -2, -3,  0, -8, -999999},
                    {0, -2, -2, -2, -2, -2, -2, -1, -2,  4,  2, -2,  2, -1, -1, -1,  0, -6, -2,  4,  0,  0,  0, -8, -999999},
                    {2,  1,  4,  5, -3,  3,  4,  2,  3, -1, -2,  2, -1, -3,  1,  2,  2, -4, -2,  0,  6,  5,  0, -8, -999999},
                    {1,  2,  3,  4, -4,  5,  5,  1,  3, -1, -1,  2,  0, -4,  1,  1,  1, -4, -3,  0,  5,  6,  0, -8, -999999},
                    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -8, -999999},
                    {-8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,  1, -999999},
                    {-999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, 
                     -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999, -999999 }};
                     
     }

/*!
 * XnuScores  destructor
 * 
 */
     ~XnuScores(){
        vector<double>().swap(Dayhoff);
        vector<double>().swap(Blast);
        vector<int>().swap(M);
        vector<vector<int>>().swap(Pam60);
        vector<vector<int>>().swap(Pam120);
        vector<vector<int>>().swap(Pam250);
        
        }

};

} // end fastaplus
