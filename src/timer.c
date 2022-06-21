/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   timer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbouma <tbouma@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 17:00:37 by tbouma        #+#    #+#                 */
/*   Updated: 2022/06/21 18:54:58 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	timer(t_philo *philo, long interval_time)
{
	struct timeval	curr_time;
	struct timeval	start_time;

	if (gettimeofday(&start_time, NULL))
		perror_msg("Timefunc:");
	if (gettimeofday(&curr_time, NULL))
		perror_msg("Timefunc:");
	while (curr_time.tv_usec - start_time.tv_usec < interval_time * 1000)
	{
		if (philo->state->someone_died == 1 && philo->is_dead == 0)
			pthread_exit(0);//exit(0);
		if (philo->is_dead == 1)
			return (1);
		usleep(250);
		if (gettimeofday(&curr_time, NULL))
			perror_msg("Timefunc:");
	}
	return (0);
}

int	d_timer(t_philo *philo, long interval_time)
{
	struct timeval	curr_time;
	struct timeval	start_time;

	if (gettimeofday(&start_time, NULL))
		perror_msg("Timefunc:");
	if (gettimeofday(&curr_time, NULL))
		perror_msg("Timefunc:");
	while (curr_time.tv_usec - start_time.tv_usec < interval_time * 1000)
	{
		if (philo->state->someone_died == 1 && philo->is_dead == 0)
			pthread_exit(0);//exit(0);
		usleep(250);
		if (philo->start_eating == 1)
		{
			if (gettimeofday(&start_time, NULL))
				perror_msg("Timefunc:");
			philo->reset_timer = 1;
			philo->start_eating = 0;
		}
		if (gettimeofday(&curr_time, NULL))
			perror_msg("Timefunc:");
	}
	return (0);
}

long	current_time_stamp(t_philo *philo)
{
	struct timeval	curr_time;
	
	if (gettimeofday(&curr_time, NULL))
		perror_msg("Timefunc:");
	return ((curr_time.tv_usec - philo->state->start_program.tv_usec) / 1000);
}

int start_program_time(t_state *state)
{
	if (gettimeofday(&state->start_program, NULL))
		perror_msg("Timefunc:");
	return (0);
}