#include <stdint.h>

#define RCC_AHB1ENR (*(volatile uint32_t*)0x40023830U)
#define RCC_APB2ENR (*(volatile uint32_t*)0x40023844U)
#define GPIOC_MODER (*(volatile uint32_t*)0x40020800U)
#define GPIOC_PUPDR (*(volatile uint32_t*)0x4002080CU)
#define GPIOA_MODER (*(volatile uint32_t*)0x40020000U)
#define GPIOA_ODR (*(volatile uint32_t*)0x40020014U)
#define GPIOC_IDR (*(volatile uint32_t*)0x40020810U)


#define EXTI_IMR (*(volatile uint32_t*)0x40013C00U)
#define EXTI_FTSR (*(volatile uint32_t*)0x40013C0CU)
#define EXTI_PR (*(volatile uint32_t*)0x40013C14U)

#define NVIC_ISER1 (*(volatile uint32_t*)0xE000E104U)

#define SYSCFG_EXTICR4 (*(volatile uint32_t*)0x40013814U)



void EXTI15_10_IRQHandler(void)
	{
		if(EXTI_PR & (1U << 13))
		{
			EXTI_PR = (1U << 13);
			GPIOA_ODR ^= (1U << 5);
		}
	}




int main(void)
{

	RCC_AHB1ENR |= (1U << 0);
	RCC_AHB1ENR  |= (1U << 2);
	RCC_APB2ENR |= (1U <<14);

	GPIOA_MODER &= ~(3U << 10);
	GPIOA_MODER |= (1U << 10);

	GPIOC_MODER &= ~(3U << 26);


	SYSCFG_EXTICR4 &= ~(0xFU << 4);

	SYSCFG_EXTICR4 |= (0x2U << 4);

	EXTI_FTSR |= (1U << 13);
	EXTI_IMR |= (1U << 13);

	NVIC_ISER1 |= (1U << 8);


\

	while(1)
	{

	}
}
