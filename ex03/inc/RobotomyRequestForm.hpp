/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:07:42 by jlara-na          #+#    #+#             */
/*   Updated: 2025/06/20 13:36:46 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AForm.hpp"
# include <sys/time.h>

class RobotomyRequestForm : public AForm
{
	private:
		const std::string	_target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm&other);
		RobotomyRequestForm(const std::string target);
		~RobotomyRequestForm();
	
		RobotomyRequestForm&		operator=(const RobotomyRequestForm& other);
		virtual void		execute(Bureaucrat const &executor) const;
};