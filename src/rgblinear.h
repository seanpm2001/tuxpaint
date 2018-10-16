/*
  rgblinear.h

  For Tux Paint
  RGB to Linear and Linear to RGB functions

  Copyright (c) 2002-2006 by Bill Kendrick and others
  bill@newbreedsoftware.com
  http://www.newbreedsoftware.com/tuxpaint/

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  (See COPYING.txt)

  June 14, 2002 - February 17, 2006
  $Id: rgblinear.h,v 1.2 2006/08/27 21:00:55 wkendrick Exp $
*/


#ifndef RGBLINEAR_H
#define RGBLINEAR_H

#include "compiler.h"

// This goes from 8-bit sRGB (range 0 to 255) to linear (range 0 to 1).
// The math to produce a table entry:
//    tmp = oldvalue / 255.0;
//    result = (tmp<=0.03928) ? tmp/12.92 : pow((tmp+0.055)/1.055,2.4);
static const float sRGB_to_linear_table[256] = {
  0.000000, 0.000304, 0.000607, 0.000911, 0.001214, 0.001518, 0.001821,
  0.002125, 0.002428, 0.002732, 0.003035, 0.003347, 0.003677, 0.004025,
  0.004391, 0.004777, 0.005182, 0.005605, 0.006049, 0.006512, 0.006995,
  0.007499, 0.008023, 0.008568, 0.009134, 0.009721, 0.010330, 0.010960,
  0.011612, 0.012286, 0.012983, 0.013702, 0.014444, 0.015209, 0.015996,
  0.016807, 0.017642, 0.018500, 0.019382, 0.020289, 0.021219, 0.022174,
  0.023153, 0.024158, 0.025187, 0.026241, 0.027321, 0.028426, 0.029557,
  0.030713, 0.031896, 0.033105, 0.034340, 0.035601, 0.036889, 0.038204,
  0.039546, 0.040915, 0.042311, 0.043735, 0.045186, 0.046665, 0.048172,
  0.049707, 0.051269, 0.052861, 0.054480, 0.056128, 0.057805, 0.059511,
  0.061246, 0.063010, 0.064803, 0.066626, 0.068478, 0.070360, 0.072272,
  0.074214, 0.076185, 0.078187, 0.080220, 0.082283, 0.084376, 0.086500,
  0.088656, 0.090842, 0.093059, 0.095307, 0.097587, 0.099899, 0.102242,
  0.104616, 0.107023, 0.109462, 0.111932, 0.114435, 0.116971, 0.119538,
  0.122139, 0.124772, 0.127438, 0.130136, 0.132868, 0.135633, 0.138432,
  0.141263, 0.144128, 0.147027, 0.149960, 0.152926, 0.155926, 0.158961,
  0.162029, 0.165132, 0.168269, 0.171441, 0.174647, 0.177888, 0.181164,
  0.184475, 0.187821, 0.191202, 0.194618, 0.198069, 0.201556, 0.205079,
  0.208637, 0.212231, 0.215861, 0.219526, 0.223228, 0.226966, 0.230740,
  0.234551, 0.238398, 0.242281, 0.246201, 0.250158, 0.254152, 0.258183,
  0.262251, 0.266356, 0.270498, 0.274677, 0.278894, 0.283149, 0.287441,
  0.291771, 0.296138, 0.300544, 0.304987, 0.309469, 0.313989, 0.318547,
  0.323143, 0.327778, 0.332452, 0.337164, 0.341914, 0.346704, 0.351533,
  0.356400, 0.361307, 0.366253, 0.371238, 0.376262, 0.381326, 0.386429,
  0.391572, 0.396755, 0.401978, 0.407240, 0.412543, 0.417885, 0.423268,
  0.428690, 0.434154, 0.439657, 0.445201, 0.450786, 0.456411, 0.462077,
  0.467784, 0.473531, 0.479320, 0.485150, 0.491021, 0.496933, 0.502886,
  0.508881, 0.514918, 0.520996, 0.527115, 0.533276, 0.539479, 0.545724,
  0.552011, 0.558340, 0.564712, 0.571125, 0.577580, 0.584078, 0.590619,
  0.597202, 0.603827, 0.610496, 0.617207, 0.623960, 0.630757, 0.637597,
  0.644480, 0.651406, 0.658375, 0.665387, 0.672443, 0.679542, 0.686685,
  0.693872, 0.701102, 0.708376, 0.715694, 0.723055, 0.730461, 0.737910,
  0.745404, 0.752942, 0.760525, 0.768151, 0.775822, 0.783538, 0.791298,
  0.799103, 0.806952, 0.814847, 0.822786, 0.830770, 0.838799, 0.846873,
  0.854993, 0.863157, 0.871367, 0.879622, 0.887923, 0.896269, 0.904661,
  0.913099, 0.921582, 0.930111, 0.938686, 0.947307, 0.955973, 0.964686,
  0.973445, 0.982251, 0.991102, 1.000000
};

// this goes the other way; range checking will be required
static const unsigned char linear_to_sRGB_table[4096] =
  "\x00\x01\x02\x03\x03\x04\x05\x06\x07\x08\x08\x09\x0a\x0b\x0b\x0c\x0d\x0d"
  "\x0e\x0f\x10\x10\x11\x11\x12\x12\x13\x13\x14\x14\x15\x15\x16\x16\x17\x17"
  "\x18\x18\x18\x19\x19\x1a\x1a\x1a\x1b\x1b\x1c\x1c\x1c\x1d\x1d\x1d\x1e\x1e"
  "\x1e\x1f\x1f\x1f\x20\x20\x20\x21\x21\x21\x22\x22\x22\x23\x23\x23\x23\x24"
  "\x24\x24\x25\x25\x25\x25\x26\x26\x26\x26\x27\x27\x27\x28\x28\x28\x28\x29"
  "\x29\x29\x29\x2a\x2a\x2a\x2a\x2b\x2b\x2b\x2b\x2c\x2c\x2c\x2c\x2c\x2d\x2d"
  "\x2d\x2d\x2e\x2e\x2e\x2e\x2f\x2f\x2f\x2f\x2f\x30\x30\x30\x30\x30\x31\x31"
  "\x31\x31\x31\x32\x32\x32\x32\x33\x33\x33\x33\x33\x34\x34\x34\x34\x34\x35"
  "\x35\x35\x35\x35\x35\x36\x36\x36\x36\x36\x37\x37\x37\x37\x37\x38\x38\x38"
  "\x38\x38\x38\x39\x39\x39\x39\x39\x39\x3a\x3a\x3a\x3a\x3a\x3a\x3b\x3b\x3b"
  "\x3b\x3b\x3c\x3c\x3c\x3c\x3c\x3c\x3d\x3d\x3d\x3d\x3d\x3d\x3d\x3e\x3e\x3e"
  "\x3e\x3e\x3e\x3f\x3f\x3f\x3f\x3f\x3f\x40\x40\x40\x40\x40\x40\x41\x41\x41"
  "\x41\x41\x41\x41\x42\x42\x42\x42\x42\x42\x42\x43\x43\x43\x43\x43\x43\x44"
  "\x44\x44\x44\x44\x44\x44\x45\x45\x45\x45\x45\x45\x45\x46\x46\x46\x46\x46"
  "\x46\x46\x46\x47\x47\x47\x47\x47\x47\x47\x48\x48\x48\x48\x48\x48\x48\x48"
  "\x49\x49\x49\x49\x49\x49\x49\x4a\x4a\x4a\x4a\x4a\x4a\x4a\x4a\x4b\x4b\x4b"
  "\x4b\x4b\x4b\x4b\x4c\x4c\x4c\x4c\x4c\x4c\x4c\x4c\x4d\x4d\x4d\x4d\x4d\x4d"
  "\x4d\x4d\x4e\x4e\x4e\x4e\x4e\x4e\x4e\x4e\x4f\x4f\x4f\x4f\x4f\x4f\x4f\x4f"
  "\x50\x50\x50\x50\x50\x50\x50\x50\x50\x51\x51\x51\x51\x51\x51\x51\x51\x51"
  "\x52\x52\x52\x52\x52\x52\x52\x52\x53\x53\x53\x53\x53\x53\x53\x53\x53\x54"
  "\x54\x54\x54\x54\x54\x54\x54\x54\x55\x55\x55\x55\x55\x55\x55\x55\x55\x56"
  "\x56\x56\x56\x56\x56\x56\x56\x56\x57\x57\x57\x57\x57\x57\x57\x57\x57\x58"
  "\x58\x58\x58\x58\x58\x58\x58\x58\x58\x59\x59\x59\x59\x59\x59\x59\x59\x59"
  "\x5a\x5a\x5a\x5a\x5a\x5a\x5a\x5a\x5a\x5a\x5b\x5b\x5b\x5b\x5b\x5b\x5b\x5b"
  "\x5b\x5b\x5c\x5c\x5c\x5c\x5c\x5c\x5c\x5c\x5c\x5c\x5d\x5d\x5d\x5d\x5d\x5d"
  "\x5d\x5d\x5d\x5e\x5e\x5e\x5e\x5e\x5e\x5e\x5e\x5e\x5e\x5e\x5f\x5f\x5f\x5f"
  "\x5f\x5f\x5f\x5f\x5f\x5f\x60\x60\x60\x60\x60\x60\x60\x60\x60\x60\x60\x61"
  "\x61\x61\x61\x61\x61\x61\x61\x61\x61\x62\x62\x62\x62\x62\x62\x62\x62\x62"
  "\x62\x62\x63\x63\x63\x63\x63\x63\x63\x63\x63\x63\x63\x64\x64\x64\x64\x64"
  "\x64\x64\x64\x64\x64\x64\x65\x65\x65\x65\x65\x65\x65\x65\x65\x65\x65\x66"
  "\x66\x66\x66\x66\x66\x66\x66\x66\x66\x66\x67\x67\x67\x67\x67\x67\x67\x67"
  "\x67\x67\x67\x67\x68\x68\x68\x68\x68\x68\x68\x68\x68\x68\x68\x69\x69\x69"
  "\x69\x69\x69\x69\x69\x69\x69\x69\x6a\x6a\x6a\x6a\x6a\x6a\x6a\x6a\x6a\x6a"
  "\x6a\x6a\x6b\x6b\x6b\x6b\x6b\x6b\x6b\x6b\x6b\x6b\x6b\x6b\x6c\x6c\x6c\x6c"
  "\x6c\x6c\x6c\x6c\x6c\x6c\x6c\x6c\x6c\x6d\x6d\x6d\x6d\x6d\x6d\x6d\x6d\x6d"
  "\x6d\x6d\x6d\x6e\x6e\x6e\x6e\x6e\x6e\x6e\x6e\x6e\x6e\x6e\x6e\x6f\x6f\x6f"
  "\x6f\x6f\x6f\x6f\x6f\x6f\x6f\x6f\x6f\x70\x70\x70\x70\x70\x70\x70\x70\x70"
  "\x70\x70\x70\x70\x71\x71\x71\x71\x71\x71\x71\x71\x71\x71\x71\x71\x71\x72"
  "\x72\x72\x72\x72\x72\x72\x72\x72\x72\x72\x72\x72\x73\x73\x73\x73\x73\x73"
  "\x73\x73\x73\x73\x73\x73\x73\x74\x74\x74\x74\x74\x74\x74\x74\x74\x74\x74"
  "\x74\x74\x75\x75\x75\x75\x75\x75\x75\x75\x75\x75\x75\x75\x75\x75\x76\x76"
  "\x76\x76\x76\x76\x76\x76\x76\x76\x76\x76\x76\x77\x77\x77\x77\x77\x77\x77"
  "\x77\x77\x77\x77\x77\x77\x77\x78\x78\x78\x78\x78\x78\x78\x78\x78\x78\x78"
  "\x78\x78\x78\x79\x79\x79\x79\x79\x79\x79\x79\x79\x79\x79\x79\x79\x79\x7a"
  "\x7a\x7a\x7a\x7a\x7a\x7a\x7a\x7a\x7a\x7a\x7a\x7a\x7b\x7b\x7b\x7b\x7b\x7b"
  "\x7b\x7b\x7b\x7b\x7b\x7b\x7b\x7b\x7b\x7c\x7c\x7c\x7c\x7c\x7c\x7c\x7c\x7c"
  "\x7c\x7c\x7c\x7c\x7c\x7d\x7d\x7d\x7d\x7d\x7d\x7d\x7d\x7d\x7d\x7d\x7d\x7d"
  "\x7d\x7e\x7e\x7e\x7e\x7e\x7e\x7e\x7e\x7e\x7e\x7e\x7e\x7e\x7e\x7e\x7f\x7f"
  "\x7f\x7f\x7f\x7f\x7f\x7f\x7f\x7f\x7f\x7f\x7f\x7f\x7f\x80\x80\x80\x80\x80"
  "\x80\x80\x80\x80\x80\x80\x80\x80\x80\x80\x81\x81\x81\x81\x81\x81\x81\x81"
  "\x81\x81\x81\x81\x81\x81\x81\x82\x82\x82\x82\x82\x82\x82\x82\x82\x82\x82"
  "\x82\x82\x82\x82\x83\x83\x83\x83\x83\x83\x83\x83\x83\x83\x83\x83\x83\x83"
  "\x83\x83\x84\x84\x84\x84\x84\x84\x84\x84\x84\x84\x84\x84\x84\x84\x84\x85"
  "\x85\x85\x85\x85\x85\x85\x85\x85\x85\x85\x85\x85\x85\x85\x85\x86\x86\x86"
  "\x86\x86\x86\x86\x86\x86\x86\x86\x86\x86\x86\x86\x86\x87\x87\x87\x87\x87"
  "\x87\x87\x87\x87\x87\x87\x87\x87\x87\x87\x87\x88\x88\x88\x88\x88\x88\x88"
  "\x88\x88\x88\x88\x88\x88\x88\x88\x88\x89\x89\x89\x89\x89\x89\x89\x89\x89"
  "\x89\x89\x89\x89\x89\x89\x89\x8a\x8a\x8a\x8a\x8a\x8a\x8a\x8a\x8a\x8a\x8a"
  "\x8a\x8a\x8a\x8a\x8a\x8b\x8b\x8b\x8b\x8b\x8b\x8b\x8b\x8b\x8b\x8b\x8b\x8b"
  "\x8b\x8b\x8b\x8b\x8c\x8c\x8c\x8c\x8c\x8c\x8c\x8c\x8c\x8c\x8c\x8c\x8c\x8c"
  "\x8c\x8c\x8c\x8d\x8d\x8d\x8d\x8d\x8d\x8d\x8d\x8d\x8d\x8d\x8d\x8d\x8d\x8d"
  "\x8d\x8d\x8e\x8e\x8e\x8e\x8e\x8e\x8e\x8e\x8e\x8e\x8e\x8e\x8e\x8e\x8e\x8e"
  "\x8e\x8f\x8f\x8f\x8f\x8f\x8f\x8f\x8f\x8f\x8f\x8f\x8f\x8f\x8f\x8f\x8f\x8f"
  "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x91"
  "\x91\x91\x91\x91\x91\x91\x91\x91\x91\x91\x91\x91\x91\x91\x91\x91\x91\x92"
  "\x92\x92\x92\x92\x92\x92\x92\x92\x92\x92\x92\x92\x92\x92\x92\x92\x92\x93"
  "\x93\x93\x93\x93\x93\x93\x93\x93\x93\x93\x93\x93\x93\x93\x93\x93\x94\x94"
  "\x94\x94\x94\x94\x94\x94\x94\x94\x94\x94\x94\x94\x94\x94\x94\x94\x95\x95"
  "\x95\x95\x95\x95\x95\x95\x95\x95\x95\x95\x95\x95\x95\x95\x95\x95\x96\x96"
  "\x96\x96\x96\x96\x96\x96\x96\x96\x96\x96\x96\x96\x96\x96\x96\x96\x96\x97"
  "\x97\x97\x97\x97\x97\x97\x97\x97\x97\x97\x97\x97\x97\x97\x97\x97\x97\x98"
  "\x98\x98\x98\x98\x98\x98\x98\x98\x98\x98\x98\x98\x98\x98\x98\x98\x98\x98"
  "\x99\x99\x99\x99\x99\x99\x99\x99\x99\x99\x99\x99\x99\x99\x99\x99\x99\x99"
  "\x9a\x9a\x9a\x9a\x9a\x9a\x9a\x9a\x9a\x9a\x9a\x9a\x9a\x9a\x9a\x9a\x9a\x9a"
  "\x9a\x9b\x9b\x9b\x9b\x9b\x9b\x9b\x9b\x9b\x9b\x9b\x9b\x9b\x9b\x9b\x9b\x9b"
  "\x9b\x9b\x9c\x9c\x9c\x9c\x9c\x9c\x9c\x9c\x9c\x9c\x9c\x9c\x9c\x9c\x9c\x9c"
  "\x9c\x9c\x9c\x9c\x9d\x9d\x9d\x9d\x9d\x9d\x9d\x9d\x9d\x9d\x9d\x9d\x9d\x9d"
  "\x9d\x9d\x9d\x9d\x9d\x9e\x9e\x9e\x9e\x9e\x9e\x9e\x9e\x9e\x9e\x9e\x9e\x9e"
  "\x9e\x9e\x9e\x9e\x9e\x9e\x9e\x9f\x9f\x9f\x9f\x9f\x9f\x9f\x9f\x9f\x9f\x9f"
  "\x9f\x9f\x9f\x9f\x9f\x9f\x9f\x9f\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0"
  "\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa1\xa1\xa1\xa1\xa1\xa1\xa1\xa1"
  "\xa1\xa1\xa1\xa1\xa1\xa1\xa1\xa1\xa1\xa1\xa1\xa1\xa2\xa2\xa2\xa2\xa2\xa2"
  "\xa2\xa2\xa2\xa2\xa2\xa2\xa2\xa2\xa2\xa2\xa2\xa2\xa2\xa2\xa3\xa3\xa3\xa3"
  "\xa3\xa3\xa3\xa3\xa3\xa3\xa3\xa3\xa3\xa3\xa3\xa3\xa3\xa3\xa3\xa3\xa3\xa4"
  "\xa4\xa4\xa4\xa4\xa4\xa4\xa4\xa4\xa4\xa4\xa4\xa4\xa4\xa4\xa4\xa4\xa4\xa4"
  "\xa4\xa5\xa5\xa5\xa5\xa5\xa5\xa5\xa5\xa5\xa5\xa5\xa5\xa5\xa5\xa5\xa5\xa5"
  "\xa5\xa5\xa5\xa5\xa6\xa6\xa6\xa6\xa6\xa6\xa6\xa6\xa6\xa6\xa6\xa6\xa6\xa6"
  "\xa6\xa6\xa6\xa6\xa6\xa6\xa7\xa7\xa7\xa7\xa7\xa7\xa7\xa7\xa7\xa7\xa7\xa7"
  "\xa7\xa7\xa7\xa7\xa7\xa7\xa7\xa7\xa7\xa8\xa8\xa8\xa8\xa8\xa8\xa8\xa8\xa8"
  "\xa8\xa8\xa8\xa8\xa8\xa8\xa8\xa8\xa8\xa8\xa8\xa8\xa8\xa9\xa9\xa9\xa9\xa9"
  "\xa9\xa9\xa9\xa9\xa9\xa9\xa9\xa9\xa9\xa9\xa9\xa9\xa9\xa9\xa9\xa9\xaa\xaa"
  "\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xaa"
  "\xaa\xaa\xab\xab\xab\xab\xab\xab\xab\xab\xab\xab\xab\xab\xab\xab\xab\xab"
  "\xab\xab\xab\xab\xab\xac\xac\xac\xac\xac\xac\xac\xac\xac\xac\xac\xac\xac"
  "\xac\xac\xac\xac\xac\xac\xac\xac\xac\xad\xad\xad\xad\xad\xad\xad\xad\xad"
  "\xad\xad\xad\xad\xad\xad\xad\xad\xad\xad\xad\xad\xad\xae\xae\xae\xae\xae"
  "\xae\xae\xae\xae\xae\xae\xae\xae\xae\xae\xae\xae\xae\xae\xae\xae\xae\xaf"
  "\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf"
  "\xaf\xaf\xaf\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0"
  "\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1"
  "\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb1\xb2\xb2\xb2\xb2\xb2\xb2"
  "\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb3"
  "\xb3\xb3\xb3\xb3\xb3\xb3\xb3\xb3\xb3\xb3\xb3\xb3\xb3\xb3\xb3\xb3\xb3\xb3"
  "\xb3\xb3\xb3\xb3\xb4\xb4\xb4\xb4\xb4\xb4\xb4\xb4\xb4\xb4\xb4\xb4\xb4\xb4"
  "\xb4\xb4\xb4\xb4\xb4\xb4\xb4\xb4\xb4\xb5\xb5\xb5\xb5\xb5\xb5\xb5\xb5\xb5"
  "\xb5\xb5\xb5\xb5\xb5\xb5\xb5\xb5\xb5\xb5\xb5\xb5\xb5\xb5\xb5\xb6\xb6\xb6"
  "\xb6\xb6\xb6\xb6\xb6\xb6\xb6\xb6\xb6\xb6\xb6\xb6\xb6\xb6\xb6\xb6\xb6\xb6"
  "\xb6\xb6\xb7\xb7\xb7\xb7\xb7\xb7\xb7\xb7\xb7\xb7\xb7\xb7\xb7\xb7\xb7\xb7"
  "\xb7\xb7\xb7\xb7\xb7\xb7\xb7\xb7\xb8\xb8\xb8\xb8\xb8\xb8\xb8\xb8\xb8\xb8"
  "\xb8\xb8\xb8\xb8\xb8\xb8\xb8\xb8\xb8\xb8\xb8\xb8\xb8\xb8\xb9\xb9\xb9\xb9"
  "\xb9\xb9\xb9\xb9\xb9\xb9\xb9\xb9\xb9\xb9\xb9\xb9\xb9\xb9\xb9\xb9\xb9\xb9"
  "\xb9\xba\xba\xba\xba\xba\xba\xba\xba\xba\xba\xba\xba\xba\xba\xba\xba\xba"
  "\xba\xba\xba\xba\xba\xba\xba\xbb\xbb\xbb\xbb\xbb\xbb\xbb\xbb\xbb\xbb\xbb"
  "\xbb\xbb\xbb\xbb\xbb\xbb\xbb\xbb\xbb\xbb\xbb\xbb\xbb\xbb\xbc\xbc\xbc\xbc"
  "\xbc\xbc\xbc\xbc\xbc\xbc\xbc\xbc\xbc\xbc\xbc\xbc\xbc\xbc\xbc\xbc\xbc\xbc"
  "\xbc\xbc\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd"
  "\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbe\xbe\xbe\xbe\xbe\xbe\xbe\xbe\xbe"
  "\xbe\xbe\xbe\xbe\xbe\xbe\xbe\xbe\xbe\xbe\xbe\xbe\xbe\xbe\xbe\xbe\xbf\xbf"
  "\xbf\xbf\xbf\xbf\xbf\xbf\xbf\xbf\xbf\xbf\xbf\xbf\xbf\xbf\xbf\xbf\xbf\xbf"
  "\xbf\xbf\xbf\xbf\xbf\xc0\xc0\xc0\xc0\xc0\xc0\xc0\xc0\xc0\xc0\xc0\xc0\xc0"
  "\xc0\xc0\xc0\xc0\xc0\xc0\xc0\xc0\xc0\xc0\xc0\xc0\xc1\xc1\xc1\xc1\xc1\xc1"
  "\xc1\xc1\xc1\xc1\xc1\xc1\xc1\xc1\xc1\xc1\xc1\xc1\xc1\xc1\xc1\xc1\xc1\xc1"
  "\xc1\xc2\xc2\xc2\xc2\xc2\xc2\xc2\xc2\xc2\xc2\xc2\xc2\xc2\xc2\xc2\xc2\xc2"
  "\xc2\xc2\xc2\xc2\xc2\xc2\xc2\xc2\xc3\xc3\xc3\xc3\xc3\xc3\xc3\xc3\xc3\xc3"
  "\xc3\xc3\xc3\xc3\xc3\xc3\xc3\xc3\xc3\xc3\xc3\xc3\xc3\xc3\xc3\xc3\xc4\xc4"
  "\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4"
  "\xc4\xc4\xc4\xc4\xc4\xc4\xc5\xc5\xc5\xc5\xc5\xc5\xc5\xc5\xc5\xc5\xc5\xc5"
  "\xc5\xc5\xc5\xc5\xc5\xc5\xc5\xc5\xc5\xc5\xc5\xc5\xc5\xc5\xc6\xc6\xc6\xc6"
  "\xc6\xc6\xc6\xc6\xc6\xc6\xc6\xc6\xc6\xc6\xc6\xc6\xc6\xc6\xc6\xc6\xc6\xc6"
  "\xc6\xc6\xc6\xc6\xc6\xc7\xc7\xc7\xc7\xc7\xc7\xc7\xc7\xc7\xc7\xc7\xc7\xc7"
  "\xc7\xc7\xc7\xc7\xc7\xc7\xc7\xc7\xc7\xc7\xc7\xc7\xc7\xc8\xc8\xc8\xc8\xc8"
  "\xc8\xc8\xc8\xc8\xc8\xc8\xc8\xc8\xc8\xc8\xc8\xc8\xc8\xc8\xc8\xc8\xc8\xc8"
  "\xc8\xc8\xc8\xc9\xc9\xc9\xc9\xc9\xc9\xc9\xc9\xc9\xc9\xc9\xc9\xc9\xc9\xc9"
  "\xc9\xc9\xc9\xc9\xc9\xc9\xc9\xc9\xc9\xc9\xc9\xc9\xca\xca\xca\xca\xca\xca"
  "\xca\xca\xca\xca\xca\xca\xca\xca\xca\xca\xca\xca\xca\xca\xca\xca\xca\xca"
  "\xca\xca\xca\xcb\xcb\xcb\xcb\xcb\xcb\xcb\xcb\xcb\xcb\xcb\xcb\xcb\xcb\xcb"
  "\xcb\xcb\xcb\xcb\xcb\xcb\xcb\xcb\xcb\xcb\xcb\xcb\xcc\xcc\xcc\xcc\xcc\xcc"
  "\xcc\xcc\xcc\xcc\xcc\xcc\xcc\xcc\xcc\xcc\xcc\xcc\xcc\xcc\xcc\xcc\xcc\xcc"
  "\xcc\xcc\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"
  "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xce\xce\xce\xce"
  "\xce\xce\xce\xce\xce\xce\xce\xce\xce\xce\xce\xce\xce\xce\xce\xce\xce\xce"
  "\xce\xce\xce\xce\xcf\xcf\xcf\xcf\xcf\xcf\xcf\xcf\xcf\xcf\xcf\xcf\xcf\xcf"
  "\xcf\xcf\xcf\xcf\xcf\xcf\xcf\xcf\xcf\xcf\xcf\xcf\xcf\xcf\xd0\xd0\xd0\xd0"
  "\xd0\xd0\xd0\xd0\xd0\xd0\xd0\xd0\xd0\xd0\xd0\xd0\xd0\xd0\xd0\xd0\xd0\xd0"
  "\xd0\xd0\xd0\xd0\xd0\xd0\xd1\xd1\xd1\xd1\xd1\xd1\xd1\xd1\xd1\xd1\xd1\xd1"
  "\xd1\xd1\xd1\xd1\xd1\xd1\xd1\xd1\xd1\xd1\xd1\xd1\xd1\xd1\xd1\xd1\xd2\xd2"
  "\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2"
  "\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd2\xd3\xd3\xd3\xd3\xd3\xd3\xd3\xd3\xd3\xd3"
  "\xd3\xd3\xd3\xd3\xd3\xd3\xd3\xd3\xd3\xd3\xd3\xd3\xd3\xd3\xd3\xd3\xd3\xd3"
  "\xd4\xd4\xd4\xd4\xd4\xd4\xd4\xd4\xd4\xd4\xd4\xd4\xd4\xd4\xd4\xd4\xd4\xd4"
  "\xd4\xd4\xd4\xd4\xd4\xd4\xd4\xd4\xd4\xd4\xd4\xd5\xd5\xd5\xd5\xd5\xd5\xd5"
  "\xd5\xd5\xd5\xd5\xd5\xd5\xd5\xd5\xd5\xd5\xd5\xd5\xd5\xd5\xd5\xd5\xd5\xd5"
  "\xd5\xd5\xd5\xd5\xd6\xd6\xd6\xd6\xd6\xd6\xd6\xd6\xd6\xd6\xd6\xd6\xd6\xd6"
  "\xd6\xd6\xd6\xd6\xd6\xd6\xd6\xd6\xd6\xd6\xd6\xd6\xd6\xd6\xd6\xd7\xd7\xd7"
  "\xd7\xd7\xd7\xd7\xd7\xd7\xd7\xd7\xd7\xd7\xd7\xd7\xd7\xd7\xd7\xd7\xd7\xd7"
  "\xd7\xd7\xd7\xd7\xd7\xd7\xd7\xd7\xd8\xd8\xd8\xd8\xd8\xd8\xd8\xd8\xd8\xd8"
  "\xd8\xd8\xd8\xd8\xd8\xd8\xd8\xd8\xd8\xd8\xd8\xd8\xd8\xd8\xd8\xd8\xd8\xd8"
  "\xd8\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9"
  "\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xda\xda\xda\xda\xda"
  "\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda"
  "\xda\xda\xda\xda\xda\xda\xda\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
  "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"
  "\xdb\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc"
  "\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdc\xdd\xdd\xdd\xdd\xdd"
  "\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xdd"
  "\xdd\xdd\xdd\xdd\xdd\xdd\xdd\xde\xde\xde\xde\xde\xde\xde\xde\xde\xde\xde"
  "\xde\xde\xde\xde\xde\xde\xde\xde\xde\xde\xde\xde\xde\xde\xde\xde\xde\xde"
  "\xde\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf"
  "\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xdf\xe0\xe0\xe0\xe0"
  "\xe0\xe0\xe0\xe0\xe0\xe0\xe0\xe0\xe0\xe0\xe0\xe0\xe0\xe0\xe0\xe0\xe0\xe0"
  "\xe0\xe0\xe0\xe0\xe0\xe0\xe0\xe0\xe0\xe1\xe1\xe1\xe1\xe1\xe1\xe1\xe1\xe1"
  "\xe1\xe1\xe1\xe1\xe1\xe1\xe1\xe1\xe1\xe1\xe1\xe1\xe1\xe1\xe1\xe1\xe1\xe1"
  "\xe1\xe1\xe1\xe1\xe2\xe2\xe2\xe2\xe2\xe2\xe2\xe2\xe2\xe2\xe2\xe2\xe2\xe2"
  "\xe2\xe2\xe2\xe2\xe2\xe2\xe2\xe2\xe2\xe2\xe2\xe2\xe2\xe2\xe2\xe2\xe2\xe3"
  "\xe3\xe3\xe3\xe3\xe3\xe3\xe3\xe3\xe3\xe3\xe3\xe3\xe3\xe3\xe3\xe3\xe3\xe3"
  "\xe3\xe3\xe3\xe3\xe3\xe3\xe3\xe3\xe3\xe3\xe3\xe3\xe4\xe4\xe4\xe4\xe4\xe4"
  "\xe4\xe4\xe4\xe4\xe4\xe4\xe4\xe4\xe4\xe4\xe4\xe4\xe4\xe4\xe4\xe4\xe4\xe4"
  "\xe4\xe4\xe4\xe4\xe4\xe4\xe4\xe4\xe5\xe5\xe5\xe5\xe5\xe5\xe5\xe5\xe5\xe5"
  "\xe5\xe5\xe5\xe5\xe5\xe5\xe5\xe5\xe5\xe5\xe5\xe5\xe5\xe5\xe5\xe5\xe5\xe5"
  "\xe5\xe5\xe5\xe5\xe6\xe6\xe6\xe6\xe6\xe6\xe6\xe6\xe6\xe6\xe6\xe6\xe6\xe6"
  "\xe6\xe6\xe6\xe6\xe6\xe6\xe6\xe6\xe6\xe6\xe6\xe6\xe6\xe6\xe6\xe6\xe6\xe7"
  "\xe7\xe7\xe7\xe7\xe7\xe7\xe7\xe7\xe7\xe7\xe7\xe7\xe7\xe7\xe7\xe7\xe7\xe7"
  "\xe7\xe7\xe7\xe7\xe7\xe7\xe7\xe7\xe7\xe7\xe7\xe7\xe7\xe8\xe8\xe8\xe8\xe8"
  "\xe8\xe8\xe8\xe8\xe8\xe8\xe8\xe8\xe8\xe8\xe8\xe8\xe8\xe8\xe8\xe8\xe8\xe8"
  "\xe8\xe8\xe8\xe8\xe8\xe8\xe8\xe8\xe8\xe9\xe9\xe9\xe9\xe9\xe9\xe9\xe9\xe9"
  "\xe9\xe9\xe9\xe9\xe9\xe9\xe9\xe9\xe9\xe9\xe9\xe9\xe9\xe9\xe9\xe9\xe9\xe9"
  "\xe9\xe9\xe9\xe9\xe9\xe9\xea\xea\xea\xea\xea\xea\xea\xea\xea\xea\xea\xea"
  "\xea\xea\xea\xea\xea\xea\xea\xea\xea\xea\xea\xea\xea\xea\xea\xea\xea\xea"
  "\xea\xea\xea\xeb\xeb\xeb\xeb\xeb\xeb\xeb\xeb\xeb\xeb\xeb\xeb\xeb\xeb\xeb"
  "\xeb\xeb\xeb\xeb\xeb\xeb\xeb\xeb\xeb\xeb\xeb\xeb\xeb\xeb\xeb\xeb\xeb\xec"
  "\xec\xec\xec\xec\xec\xec\xec\xec\xec\xec\xec\xec\xec\xec\xec\xec\xec\xec"
  "\xec\xec\xec\xec\xec\xec\xec\xec\xec\xec\xec\xec\xec\xec\xec\xed\xed\xed"
  "\xed\xed\xed\xed\xed\xed\xed\xed\xed\xed\xed\xed\xed\xed\xed\xed\xed\xed"
  "\xed\xed\xed\xed\xed\xed\xed\xed\xed\xed\xed\xed\xee\xee\xee\xee\xee\xee"
  "\xee\xee\xee\xee\xee\xee\xee\xee\xee\xee\xee\xee\xee\xee\xee\xee\xee\xee"
  "\xee\xee\xee\xee\xee\xee\xee\xee\xee\xef\xef\xef\xef\xef\xef\xef\xef\xef"
  "\xef\xef\xef\xef\xef\xef\xef\xef\xef\xef\xef\xef\xef\xef\xef\xef\xef\xef"
  "\xef\xef\xef\xef\xef\xef\xf0\xf0\xf0\xf0\xf0\xf0\xf0\xf0\xf0\xf0\xf0\xf0"
  "\xf0\xf0\xf0\xf0\xf0\xf0\xf0\xf0\xf0\xf0\xf0\xf0\xf0\xf0\xf0\xf0\xf0\xf0"
  "\xf0\xf0\xf0\xf0\xf1\xf1\xf1\xf1\xf1\xf1\xf1\xf1\xf1\xf1\xf1\xf1\xf1\xf1"
  "\xf1\xf1\xf1\xf1\xf1\xf1\xf1\xf1\xf1\xf1\xf1\xf1\xf1\xf1\xf1\xf1\xf1\xf1"
  "\xf1\xf1\xf2\xf2\xf2\xf2\xf2\xf2\xf2\xf2\xf2\xf2\xf2\xf2\xf2\xf2\xf2\xf2"
  "\xf2\xf2\xf2\xf2\xf2\xf2\xf2\xf2\xf2\xf2\xf2\xf2\xf2\xf2\xf2\xf2\xf2\xf2"
  "\xf3\xf3\xf3\xf3\xf3\xf3\xf3\xf3\xf3\xf3\xf3\xf3\xf3\xf3\xf3\xf3\xf3\xf3"
  "\xf3\xf3\xf3\xf3\xf3\xf3\xf3\xf3\xf3\xf3\xf3\xf3\xf3\xf3\xf3\xf3\xf4\xf4"
  "\xf4\xf4\xf4\xf4\xf4\xf4\xf4\xf4\xf4\xf4\xf4\xf4\xf4\xf4\xf4\xf4\xf4\xf4"
  "\xf4\xf4\xf4\xf4\xf4\xf4\xf4\xf4\xf4\xf4\xf4\xf4\xf4\xf4\xf4\xf5\xf5\xf5"
  "\xf5\xf5\xf5\xf5\xf5\xf5\xf5\xf5\xf5\xf5\xf5\xf5\xf5\xf5\xf5\xf5\xf5\xf5"
  "\xf5\xf5\xf5\xf5\xf5\xf5\xf5\xf5\xf5\xf5\xf5\xf5\xf5\xf5\xf6\xf6\xf6\xf6"
  "\xf6\xf6\xf6\xf6\xf6\xf6\xf6\xf6\xf6\xf6\xf6\xf6\xf6\xf6\xf6\xf6\xf6\xf6"
  "\xf6\xf6\xf6\xf6\xf6\xf6\xf6\xf6\xf6\xf6\xf6\xf6\xf7\xf7\xf7\xf7\xf7\xf7"
  "\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7"
  "\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf7\xf8\xf8\xf8\xf8\xf8\xf8\xf8"
  "\xf8\xf8\xf8\xf8\xf8\xf8\xf8\xf8\xf8\xf8\xf8\xf8\xf8\xf8\xf8\xf8\xf8\xf8"
  "\xf8\xf8\xf8\xf8\xf8\xf8\xf8\xf8\xf8\xf8\xf8\xf9\xf9\xf9\xf9\xf9\xf9\xf9"
  "\xf9\xf9\xf9\xf9\xf9\xf9\xf9\xf9\xf9\xf9\xf9\xf9\xf9\xf9\xf9\xf9\xf9\xf9"
  "\xf9\xf9\xf9\xf9\xf9\xf9\xf9\xf9\xf9\xf9\xfa\xfa\xfa\xfa\xfa\xfa\xfa\xfa"
  "\xfa\xfa\xfa\xfa\xfa\xfa\xfa\xfa\xfa\xfa\xfa\xfa\xfa\xfa\xfa\xfa\xfa\xfa"
  "\xfa\xfa\xfa\xfa\xfa\xfa\xfa\xfa\xfa\xfa\xfb\xfb\xfb\xfb\xfb\xfb\xfb\xfb"
  "\xfb\xfb\xfb\xfb\xfb\xfb\xfb\xfb\xfb\xfb\xfb\xfb\xfb\xfb\xfb\xfb\xfb\xfb"
  "\xfb\xfb\xfb\xfb\xfb\xfb\xfb\xfb\xfb\xfc\xfc\xfc\xfc\xfc\xfc\xfc\xfc\xfc"
  "\xfc\xfc\xfc\xfc\xfc\xfc\xfc\xfc\xfc\xfc\xfc\xfc\xfc\xfc\xfc\xfc\xfc\xfc"
  "\xfc\xfc\xfc\xfc\xfc\xfc\xfc\xfc\xfc\xfd\xfd\xfd\xfd\xfd\xfd\xfd\xfd\xfd"
  "\xfd\xfd\xfd\xfd\xfd\xfd\xfd\xfd\xfd\xfd\xfd\xfd\xfd\xfd\xfd\xfd\xfd\xfd"
  "\xfd\xfd\xfd\xfd\xfd\xfd\xfd\xfd\xfd\xfd\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe"
  "\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe"
  "\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xff\xff\xff\xff\xff\xff\xff\xff"
  "\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff";

unsigned char linear_to_sRGB(float linear) FUNCTION;

#endif