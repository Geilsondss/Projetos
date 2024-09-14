(** Lógica Computacional 1 - 2024/1 *)
(** Projeto: formalização da correção do algoritmo bubblesort utilizando a estrutura de listas.**)
(** Necessário provar que o algoritmo bubblesort permuta e ordena uma lista**)
(** Link do site do coq se vocês prefirirem: https://coq.vercel.app/scratchpad.html 
  
Nome e username dos participantes:
1. Geilson - Geilsondss 
2. Wesley - ShadowmereSmith
3. Karina - Kescalona
*)

Require Import Arith List Lia.
Require Import Recdef Permutation.
Print Permutation.

Function bubble l {measure length l} := match l with
            | nil => nil
            | h::nil => h::nil
            | h1::h2::l' => if h1 <=? h2 then (h1::(bubble (h2::l'))) else (h2::(bubble (h1::l')))
                                                                           end.
Proof.
  - intros. simpl. lia.
  - intros. simpl. lia.
Defined.
Lemma ex1: bubble (3::2::1::nil) = 2::1::3::nil.
Proof.
  rewrite bubble_equation. simpl. rewrite bubble_equation. simpl. rewrite bubble_equation. reflexivity.
Qed.

Fixpoint  bubblesort l := match l with
          | nil => nil
          | h::l' => bubble (h::(bubblesort l'))  end.

Lemma ex2: (bubblesort (3::2::1::nil)) = 1::2::3::nil.
Proof.
  simpl. replace (bubble (1::nil)) with (1::nil).
  - replace (bubble (2::1::nil)) with (1::2::nil).
    + rewrite bubble_equation. simpl. rewrite bubble_equation. simpl. rewrite bubble_equation. reflexivity.
    + rewrite bubble_equation. simpl. rewrite bubble_equation. simpl. reflexivity.
  - rewrite bubble_equation. reflexivity.
Qed.

              
(*Ordenação*)
Inductive sorted: list nat -> Prop :=
| sorted_nil: sorted nil
| sorted_one: forall x, sorted (x::nil)
| sorted_all: forall x y l, sorted (y::l) -> x <= y -> sorted (x::y::l).

Lemma sorted_auxi: forall l', sorted l' -> bubble l' = l'.
Proof.
  intro l'. functional induction (bubble l').
   - intro H. reflexivity.
   - intro H. reflexivity.
   - intro H. inversion H; subst. apply IHl in H2. rewrite H2. reflexivity.
   - intro H. inversion H. subst. apply leb_correct in H4. rewrite e0 in H4.  discriminate.
Qed.

Lemma sorted_bubble: forall l' x, sorted l' -> sorted (bubble (x::l')).
Proof.
  intros l' x H. induction H.
  - rewrite  bubble_equation. apply sorted_one.
  - rewrite bubble_equation. destruct (x <=? x0) eqn: H.
    + rewrite bubble_equation. apply sorted_all.
      * apply sorted_one.
      * apply leb_complete. assumption.
    + rewrite bubble_equation. apply sorted_all.
      * apply sorted_one.
      * apply  Nat.leb_nle in H. apply not_le in H. unfold gt in H. lia.
  - rewrite bubble_equation. destruct (x <=? x0 ) eqn: H'.
    + rewrite sorted_auxi.
      * apply sorted_all.
        ** apply sorted_all; assumption.
        ** apply leb_complete. assumption.
      * apply sorted_all; assumption.
    + rewrite bubble_equation.
      * destruct (x <=? y) eqn: H''.
        ** rewrite sorted_auxi.
          *** apply sorted_all.
            **** rewrite sorted_auxi in IHsorted. assumption.
              ***** apply sorted_all.
              ****** assumption.
              ****** apply leb_complete; assumption.
            ****apply  Nat.leb_nle in H'. lia.
          *** assumption.
        ** rewrite bubble_equation in IHsorted. rewrite H'' in IHsorted. apply sorted_all.
          *** apply IHsorted.
          *** assumption.
Qed.
      
Lemma bubblesort_ordena: forall l, sorted (bubblesort l).
Proof.
  induction l.
  - simpl. apply sorted_nil.
  - simpl. apply sorted_bubble. apply IHl.
Qed.

(* Permutação - OK *)
Inductive Permutation: list nat -> list nat -> Prop :=
| perm_self: forall l, Permutation l l
| perm_skip: forall x l l', Permutation l l' -> Permutation (x::l) (x::l')
| perm_swap: forall x y l l', Permutation l l' -> Permutation  (x::y::l) (y::x::l')
| perm_trans: forall l l' l'', Permutation l l' -> Permutation l' l'' -> Permutation l l''.

Lemma perm_bubble: forall l, Permutation l (bubble l).
Proof.
  intro l. functional induction (bubble l).
  - apply perm_self.
  - apply perm_self.
  - apply perm_skip. apply IHl0.
  - apply perm_trans with (h2::h1::l').
    + apply perm_swap. apply perm_self.
    + apply perm_skip. apply IHl0.
Qed.

Lemma bubblesort_perm: forall l, Permutation l (bubblesort l).
Proof.
  induction l.
  - simpl. apply perm_self.
  - simpl. apply perm_trans with (a::(bubblesort l)).
    + apply perm_skip. apply IHl.
    + apply perm_bubble.
Qed.

Theorem bubblesort_correto: forall l, sorted (bubblesort l) /\ Permutation l (bubblesort l).
Proof.
intro l. split.
- apply bubblesort_ordena.
- apply bubblesort_perm.
Qed.






              
