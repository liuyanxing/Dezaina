declare type WindingRule = 'NONZERO' | 'EVENODD'
declare type Unit = 'PIXELS' | 'PERCENT'
interface LetterSpacing {
  readonly value: float
  readonly unit: Unit
}
