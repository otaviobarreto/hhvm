/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-present Facebook, Inc. (http://www.facebook.com)  |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/
#include "hphp/runtime/base/rds-util.h"

#include "hphp/runtime/vm/func.h"
#include "hphp/runtime/vm/named-entity.h"

namespace HPHP { namespace rds {

//////////////////////////////////////////////////////////////////////

Link<RefData, true /* normal_only */>
bindStaticLocal(const Func* func, const StringData* name) {
  auto ret = bind<RefData,true>(
    StaticLocal { func->getFuncId(), name },
    Mode::Normal
  );
  return ret;
}

Link<TypedValue, true /* normal_only */>
bindClassConstant(const StringData* clsName, const StringData* cnsName) {
  auto ret = bind<TypedValue,true,kTVSimdAlign>(
    ClsConstant { clsName, cnsName },
    Mode::Normal
  );
  return ret;
}

//////////////////////////////////////////////////////////////////////

}}
