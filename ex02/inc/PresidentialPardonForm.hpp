/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:07:37 by jlara-na          #+#    #+#             */
/*   Updated: 2025/04/15 10:17:15 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string	_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm&other);
		PresidentialPardonForm(const std::string target);
		~PresidentialPardonForm();

		PresidentialPardonForm&		operator=(const PresidentialPardonForm& other);
		virtual void		execute(Bureaucrat const &executor) const;
};