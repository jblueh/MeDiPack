/*
 * MeDiPack, a Message Differentiation Package
 *
 * Copyright (C) 2015-2026 Chair for Scientific Computing (SciComp), University of Kaiserslautern-Landau
 * Homepage: http://scicomp.rptu.de
 * Contact:  Prof. Nicolas R. Gauger (codi@scicomp.uni-kl.de)
 *
 * Lead developers: Max Sagebaum (SciComp, University of Kaiserslautern-Landau)
 *
 * This file is part of MeDiPack (http://scicomp.rptu.de/software/medi).
 *
 * MeDiPack is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * MeDiPack is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU Lesser General Public License for more details.
 * You should have received a copy of the GNU
 * Lesser General Public License along with MeDiPack.
 * If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors: Max Sagebaum, Tim Albring (SciComp, University of Kaiserslautern-Landau)
 */

#pragma once

#include "adToolInterface.h"
#include "macros.h"
#include "typeDefinitions.h"

/**
 * @brief Global namespace for MeDiPack - Message Differentiation Package
 */
namespace medi {

  /**
   * @brief Implementation for the AD tool interface of a type that is no AD type.
   *
   * All methods in this implementation contain no logic.
   */
  class ADToolPassive final : public ADToolBase<ADToolPassive, char, char, char> {
    public:

      using PrimalType = char;
      using AdjointType = char;
      using IndexType = char;

      using CallbackFuncTyped = void (*)(IndexType* id, void* userData);
      using Base = ADToolBase<ADToolPassive, char, char, char>;

      ADToolPassive(MPI_Datatype primalType, MPI_Datatype adjointType) :
        Base(primalType, adjointType)
      {}

      inline bool isActiveType() const {return false;}
      inline bool isHandleRequired() const {return false;}
      inline bool isModifiedBufferRequired() const {return false;}
      inline bool isOldPrimalsRequired() const {return false;}
      inline void startAssembly(HandleBase* h) const {MEDI_UNUSED(h);}
      inline void stopAssembly(HandleBase* h) const {MEDI_UNUSED(h);}
      inline void addToolAction(HandleBase* h) const {MEDI_UNUSED(h);}

      inline AMPI_Op convertOperator(AMPI_Op op) const {
        return op;
      }

      using Base::createPrimalTypeBuffer;
      inline void createPrimalTypeBuffer(PrimalType* &buf, size_t size) const {
        MEDI_UNUSED(size);

        buf = nullptr;
      }

      using Base::createIndexTypeBuffer;
      inline void createIndexTypeBuffer(IndexType* &buf, size_t size) const {
        MEDI_UNUSED(size);

        buf = nullptr;
      }

      using Base::deletePrimalTypeBuffer;
      inline void deletePrimalTypeBuffer(PrimalType* &buf) const {
        buf = nullptr;
      }

      using Base::deleteIndexTypeBuffer;
      inline void deleteIndexTypeBuffer(IndexType* &buf) const {
        buf = nullptr;
      }

      using Base::iterateIdentifiers;
      void iterateIdentifiers(void* indices, int elements, CallbackFuncTyped func, void* userData) const {
        (void)indices;
        (void)elements;
        (void)func;
        (void)userData;
      }
  };
}
