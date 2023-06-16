/**
 * This file is a part of the UMSKT Project
 *
 * Copyleft (C) 2019-2023 UMSKT Contributors (et.al.)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.

 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @FileCreated by Neo on 6/6/2023
 * @Maintainer Neo
 */

#ifndef UMSKT_BINK1998_H
#define UMSKT_BINK1998_H

#include "header.h"

class BINK1998 {
    static void Unpack(
            QWORD (&pRaw)[2],
             BOOL &pUpgrade,
            DWORD &pSerial,
            DWORD &pHash,
            QWORD &pSignature
    );
    static void Pack(
            QWORD (&pRaw)[2],
             BOOL pUpgrade,
            DWORD pSerial,
            DWORD pHash,
            QWORD pSignature
    );

public:
    static bool Verify(
            EC_GROUP *eCurve,
            EC_POINT *basePoint,
            EC_POINT *publicKey,
                char (&pKey)[25]
    );
    static void Generate(
            EC_GROUP *eCurve,
            EC_POINT *basePoint,
              BIGNUM *genOrder,
              BIGNUM *privateKey,
               DWORD pSerial,
                BOOL pUpgrade,
                char (&pKey)[25]
    );
};

#endif //UMSKT_BINK1998_H
