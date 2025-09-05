/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:43:50 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/04 21:34:50 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug() {
  std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void Harl::info() {
  std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}
void Harl::warning() {
  std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}
void Harl::error() {
  std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

//corresponding method based on the level (such as “DEBUG”).
void Harl::complain(const std::string& level) {
  //Define a pointer type to Harl's member functions with no arguments and no return value under the alias Fn.
  typedef void (Harl::*Fn)();
  //small structure that pairs a string label with a function pointer.
  struct Pair { const char* name; Fn fn; };
  static const Pair table[4] = {
    { "DEBUG", &Harl::debug },
    { "INFO", &Harl::info },
    { "WARNING", &Harl::warning },
    { "ERROR", &Harl::error }
  };
  int i = 0;
  while (i < 4) {
    //Compare the argument level matches the label of the current line.
    if (level == table[i].name) {
      //見つかった行から対応するメンバ関数ポインタを取り出して f に格納。
      Fn f = table[i].fn;
      //メンバ関数ポインタを**this に対して呼び出し**（Harl の該当メソッドを実行）。
      (this->*f)();
      return;
    }
    ++i;
  }
}

// 「INFO」が渡されたときの挙動を順に説明します。
// 関数ポインタ型 Fn（void (Harl::*)()）と、文字列ラベルと関数ポインタの組 Pair を定義。
// 静的配列 table に、レベル名 → 対応メソッドの対応表を用意：DEBUG→debug, INFO→info, WARNING→warning, ERROR→error。
// i = 0 からループ開始。
// i=0: level("INFO") == "DEBUG" は不一致 → i=1。
// i=1: level("INFO") == "INFO" が一致。
// 一致した行の関数ポインタを取り出し、Fn f = table[1].fn;（= &Harl::info）。
// メンバ関数ポインタ呼び出し構文で実行：(this->*f)(); → つまり this->info() を呼ぶ。
// 直後に return; で関数を終了。以降のレベルは見ない。
// 結果として、Harl::info() の本文が実行され、コンソールに次のメッセージが出力されます。
