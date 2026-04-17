import React from 'react'
import { Box, Text } from 'ink'

export interface BarChartProps {
  items: { label: string; value: number; color: string }[]
  maxWidth?: number
}

export function BarChart({ items, maxWidth = 10 }: BarChartProps) {
  const max = items.length > 0 ? Math.max(...items.map(i => i.value)) : 0

  return (
    <Box flexDirection="column">
      {items.map(({ label, value, color }) => {
        const width = max > 0 ? Math.max(1, Math.round((value / max) * maxWidth)) : 1
        return (
          <Box key={label}>
            <Text color={color}>{'█'.repeat(width)}</Text>
            <Text> {label}</Text>
          </Box>
        )
      })}
    </Box>
  )
}
